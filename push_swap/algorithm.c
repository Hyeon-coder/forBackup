/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:59:18 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/20 21:48:30 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	get_max_bits(t_stack *stack)
{
	int		max;
	int		bits;
	t_stack	*temp;

	max = 0;
	bits = 0;
	temp = stack;
	while (temp)
	{
		if (temp->num > max)
			max = temp->num;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	if (is_sorted(*a))
		return ;
	size = ft_lstsize(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->num >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a, 1);
			j++;
		}
		while (*b)
			pa(b, a);
		i++;
	}
}
