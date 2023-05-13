/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:37:28 by chabrune          #+#    #+#             */
/*   Updated: 2023/05/13 15:04:10 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	struct timeval	beginning_ms;
	pthread_mutex_t	logs;
}					t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_done;
	long int		last_meal;
	pthread_mutex_t	*fork;
	t_data			*datas;
}					t_philo;

long int			get_time(t_philo *philo);
long int			last_meal(long int time_last_meal, t_philo *philo);
int					initialize_dinning_table(t_data *datas, t_philo *all_philo);
void				print_logs(t_philo *philo, char *str);
void				*routine(void *arg);
int					init_data(char **ar, t_data *datas);
t_philo				*init_philos(t_data *datas);
int					set_philo(t_data *datas, t_philo *philos,
						pthread_mutex_t *fork);
int					check_argv(char **argv);
int					ft_check_int(char *str);
int					ft_atoi(const char *str);
int					set_philo(t_data *datas, t_philo *philos,
						pthread_mutex_t *fork);
int					ft_strlen(const char *str);

#endif
