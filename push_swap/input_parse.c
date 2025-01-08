/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:05:34 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/01/08 16:30:13 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, str[i], 1);
}

static int	ft_atoi(const char *nptr)
{
	int	num;
	int	flag;
	int	i;

	num = 0;
	flag = 1;
	i = 0;
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t'
			|| nptr[i] == '\n' || nptr[i] == '\r'
			|| nptr[i] == '\v' || nptr[i] == '\f'))
		i++;
	if (nptr[i] == '-')
	{
		flag *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * flag);
}

static int	ft_isint(char *nb)
{
	int	i;
	int	num;
	int	flag;

	i = 0;
	if (!('0' <= nb[i] && nb[i] <= 9) && nb != '-')
		return (0);
	if (-2147483648 <= ft_atoi(nb) && ft_atoi(nb) <= 2147483647)
		return (0);
}

int	input_parse(int ac, char **av)
{
	int	arr[ac-1];
	int	i;

	if (ac < 2)
		ft_putstr("Error");	
	if (ft_isint())
}