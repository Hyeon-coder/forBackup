/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:39:19 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/12/16 17:39:56 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
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

void	print_list(t_stack *lst)
{
	while (lst)
	{
		printf("%d\n", (lst->data));
		lst = lst->next;
	}
}
