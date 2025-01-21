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

int	calculate_pivot(t_stack *a)
{
	int	*arr;
	int	pivot;

	arr = stack_to_array(a, ft_lstsize(a));
	sort_array(arr, ft_lstsize(a));
	pivot = arr[ft_lstsize(a) / 2];
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

void quicksort_stack(t_stack **a, t_stack **b)
{
	int pivot;
	int	i;

	i = ft_lstsize(*a);
	pivot = calculate_pivot(*a);
	printf("pivot >>> %d\n", pivot);
	while (i--)
	{
		if (stack_peek(*a) < pivot)
			pa(a, b);
		else
			ra(a, 1);
	}
	printf("--a--\n");
	print_list(*a);
	printf("--b--\n");
	print_list(*b);
}
