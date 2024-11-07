/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:33:55 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/11/07 15:22:35 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	flag;
	int	sign;
	int	rst;
	int	i;

	rst = 0;
	i = 0;
	sign = 1;
	flag = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' || \
		       	nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
	{
		if (nptr[i] == '-' || nptr[i] == '+')
			sign *= -1;
		i++;
	}
	while (nptr[i] && flag)
	{
		if (ft_isdigit(nptr[i]))
			rst = rst * 10 + (nptr[i] - '0');
		else
			flag = 0;
		i++;
	}
	return (sign * rst);
}
