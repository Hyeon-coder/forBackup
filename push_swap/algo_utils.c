/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 07:40:08 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/27 19:21:54 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *a, int size)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		exit_error(1, a, NULL);
	i = 0;
	while (a)
	{
		arr[i] = a->num;
		a = a->next;
		i++;
	}
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	size--;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	calculate_pivot(t_stack *a)
{
	int	*arr;
	int	pivot;

	arr = stack_to_array(a, ft_lstsize(a));
	if (!arr)
		return (0);
	sort_array(arr, ft_lstsize(a));
	pivot = arr[ft_lstsize(a) / 2];
	free(arr);
	return (pivot);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
