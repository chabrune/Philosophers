/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:19:14 by chabrune          #+#    #+#             */
/*   Updated: 2023/05/13 15:03:58 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) <= 0)
			return (1);
		if (ft_check_int(argv[i]) == 1)
			return (2);
	}
	return (0);
}

int	ft_check_int(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			check++;
		i++;
	}
	if (check == ft_strlen(str))
		return (0);
	else
		return (1);
}
