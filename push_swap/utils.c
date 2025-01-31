/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:04:08 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/15 08:56:50 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)

void	exit_error(int i, t_stack *a, t_stack *b)
{
	if (i == 1)
		write(2, "Error\n", 6);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}

int	ft_atoi(const char *str)
{
	long num;
	long flag;

	num = 0;
	flag = 1;
	if (*str == '-' || *str == '+')
	{
		if (!(*(str + 1) >= '0' && *(str + 1) <= '9'))
			exit_error(1, NULL, NULL);
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if ((flag == 1 && num > INT_MAX) || (flag == -1 && -num < INT_MIN))
			exit_error(1, NULL, NULL);
		str++;
	}
	return ((int)(num * flag));
}

t_stack	*ft_lstnew(int num)
{
	t_stack	*n_num;

	n_num = (t_stack *)malloc(sizeof(*n_num));
	if (!n_num)
		return (NULL);
	n_num->num = num;
	n_num->next = NULL;
	return (n_num);
}
