/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:49:45 by chabrune          #+#    #+#             */
/*   Updated: 2023/05/13 14:25:17 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (result > 2147483647)
			return (-1);
		i++;
	}
	return (result);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_size(long int n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		n = -n;
		size++;
	}
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*tab;
	int			size;
	long int	ln;

	ln = (long int)n;
	size = count_size(ln);
	tab = malloc((size + 1) * sizeof(char));
	if (!tab)
		return (0);
	if (ln < 0)
	{
		tab[0] = '-';
		ln = -ln;
	}
	tab[size] = 0;
	size--;
	if (ln == 0)
		tab[0] = '0';
	while (ln > 0)
	{
		tab[size] = ln % 10 + '0';
		ln /= 10;
		size--;
	}
	return (tab);
}
