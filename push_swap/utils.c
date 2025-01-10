/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:04:08 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/09 23:22:46 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	long	num;
	int		flag;

	num = 0;
	flag = 1;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (-2147483648 < (num * flag) || (num * flag) < 2147483647)
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
