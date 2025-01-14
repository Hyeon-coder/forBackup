/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:59:18 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/14 12:12:44 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_pivot(t_stack *a)
{
	int	*arr;
	int	pivot;

	arr = stack_to_array(a, a->size);
	sort_array(arr, a->size);
	pivot = arr[a->size / 2];
	free(arr);
	return (pivot);
}

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
	while ((*a)->size > 3)
		pa(a, b);
	sort_three(a);
	while (*b)
		pb(b, a);
}

void	quicksort_stack(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	count;
	
	if (size <= 3)
	{
		sort_three(a);
		return ;
	}
	pivot = calculate_pivot(*a);
	count = 0;
	while (count < size)
	{
		if ((*a)->num < pivot)
			pa(a, b);
		else
			ra(a, 1);
		count++;
	}
	quicksort_stack(a, b, size / 2);
	quicksort_stack(b, a, size - size / 2);
}
