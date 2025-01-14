/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:59:18 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/13 07:42:48 by JuHyeon          ###   ########.fr       */
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
		ps_swap(a);
	else if (top > mid && mid > bottom)
	{
		ps_swap(a);
		ps_reverse(a);
	}
	else if (top > bottom && mid < bottom)
		ps_rotate(a);
	else if (top < mid && mid > bottom && top < bottom)
	{
		ps_swap(a);
		ps_rotate(a);
	}
	else if (top < mid && mid > bottom && top > bottom)
		ps_reverse(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
		ps_push(a, b);
	sort_three(a);
	while (*b)
		ps_push(b, a);
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
			ps_push(a, b);
		else
			ps_rotate(a);
		count++;
	}
	quicksort_stack(a, b, size / 2);
	quicksort_stack(b, a, size - size / 2);
}
