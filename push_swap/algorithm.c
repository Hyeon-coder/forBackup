/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:59:18 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/15 10:45:09 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*a)->num;
	mid = (*a)->next->num;
	bottom = (*a)->next->next->num;
	if (top > mid && mid < bottom && top < bottom)
		sa(a, 1);
	else if (top > mid && mid > bottom)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (top > bottom && mid < bottom)
		ra(a, 1);
	else if (top < mid && mid > bottom && top < bottom)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (top < mid && mid > bottom && top > bottom)
		rra(a, 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int pivot;

	pivot = calculate_pivot(*a);
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->num < pivot)
			pb(a, b);
		else
			ra(a, 1);
	}
	sort_three(a);
	while (*b)
	{
		rrb(b, 1);
		pa(b, a);
	}
}

void partition_stack(t_stack **a, t_stack **b, int pivot, int *moved_to_b)
{
	int size_a;
	int i;

	size_a = ft_lstsize(*a);
	*moved_to_b = 0;
	i = size_a;
	while (i-- > 0)
	{
		if (stack_peek(*a) < pivot)
		{
			pb(a, b);
			(*moved_to_b)++;
			if (ft_lstsize(*b) > 1 && stack_peek(*b) < (*b)->next->num)
				sb(b, 1);
		}
		else
			ra(a, 1);
	}
}

void merge_stack(t_stack **a, t_stack **b, int moved_to_b)
{
	while (moved_to_b-- > 0)
	{
		pa(b, a);
		if (ft_lstsize(*a) > 1 && stack_peek(*a) > (*a)->next->num)
			sa(a, 1);
	}
}

void quicksort_stack(t_stack **a, t_stack **b)
{
	int pivot;
	int moved_to_b;

	if (ft_lstsize(*a) <= 1 || is_sorted(*a))
		return;

	pivot = calculate_pivot(*a);
	partition_stack(a, b, pivot, &moved_to_b);
	quicksort_stack(a, b);
	merge_stack(a, b, moved_to_b);

	if (!is_sorted(*a))
		quicksort_stack(a, b);
}
