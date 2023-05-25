/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:24:19 by chabrune          #+#    #+#             */
/*   Updated: 2023/05/13 15:04:18 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(t_philo *philo)
{
	long int		time;
	long int		time_beginning;
	struct timeval	tv;

	gettimeofday(&(tv), NULL);
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	time_beginning = ((philo->datas->beginning_ms.tv_sec * 1000)
			+ (philo->datas->beginning_ms.tv_usec / 1000));
	return (time - time_beginning);
}
long int	last_meal(long int time_last_meal, t_philo *philo)
{
	long int	time;

	time = get_time(philo);
	return (time - time_last_meal);
}
