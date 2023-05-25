/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <chabrune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:38:10 by chabrune          #+#    #+#             */
/*   Updated: 2023/05/25 13:23:37 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_dinning_table(t_data *datas, t_philo *all_philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < datas->nb_philo)
		{
			if (all_philo[i].meals_done > datas->must_eat
				&& datas->must_eat > 0)
				return (1);
			if (last_meal(all_philo[i].last_meal,
							all_philo) > (datas->time_to_die))
			{
				pthread_mutex_lock(&(datas->logs));
				printf("%ldms %d died\n", get_time(all_philo), i);
				return (1);
			}
			i++;
			usleep(100);
		}
	}
	return (0);
}

void	print_logs(t_philo *philo, char *str)
{
	long int	time;

	time = get_time(philo);
	pthread_mutex_lock(&(philo->datas->logs));
	printf("%ldms %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&(philo->datas->logs));
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		pthread_mutex_lock(&(philo->fork[philo->id]));
		print_logs(philo, "has taken a fork");
		pthread_mutex_lock(&(philo->fork[(philo->id + 1)
					% philo->datas->nb_philo]));
		print_logs(philo, "has taken a fork");
		print_logs(philo, "is eating");
		philo->meals_done++;
		usleep((philo->datas->time_to_eat) * 1000);
		philo->last_meal = get_time(philo);
		pthread_mutex_unlock(&(philo->fork[philo->id]));
		pthread_mutex_unlock(&(philo->fork[(philo->id + 1)
					% philo->datas->nb_philo]));
		print_logs(philo, "is sleeping");
		usleep((philo->datas->time_to_sleep) * 1000);
		print_logs(philo, "is thinking");
	}
	return (arg);
}

int	init_data(char **ar, t_data *datas, int argc)
{
	if (pthread_mutex_init(&datas->logs, NULL) != 0)
		return (-1);
	datas->nb_philo = ft_atoi(ar[1]);
	datas->time_to_die = ft_atoi(ar[2]);
	datas->time_to_eat = ft_atoi(ar[3]);
	datas->time_to_sleep = ft_atoi(ar[4]);
	if (datas->nb_philo <= 0 || datas->time_to_die <= 0
		|| datas->time_to_eat <= 0 || datas->time_to_sleep <= 0)
		return (-1);
	if (argc == 6)
		datas->must_eat = ft_atoi(ar[5]);
	else
		datas->must_eat = -1;
	if (gettimeofday(&datas->beginning_ms, NULL) == -1)
		return (-1);
	return (0);
}

int	set_philo(t_data *datas, t_philo *philos, pthread_mutex_t *fork)
{
	int	i;

	i = -1;
	while (++i < datas->nb_philo)
	{
		if (pthread_mutex_init(&(fork[i]), NULL) != 0)
			return (-1);
	}
	i = -1;
	while (++i < datas->nb_philo)
	{
		philos[i].fork = fork;
		philos[i].datas = datas;
		philos[i].id = i;
		philos[i].meals_done = 0;
		philos[i].last_meal = get_time(philos);
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
			return (-1);
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	datas;
	t_philo	*philos;
	pthread_mutex_t	*fork;

	if (argc == 5 || argc == 6)
	{
		if (check_argv(argv) > 0)
			return (printf("Error\n"));
		if (init_data(argv, &datas, argc) == -1)
			return (printf("Error\n"));
		philos = malloc(sizeof(t_philo) * datas.nb_philo);
		fork = malloc(sizeof(pthread_mutex_t) * datas.nb_philo);
		if (!philos || !fork)
			return (1);
		if (set_philo(&datas, philos, fork) == -1)
			return (printf("Error\n"));
		initialize_dinning_table(&datas, philos);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
