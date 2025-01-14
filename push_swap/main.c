/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:14 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/13 07:34:37 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *lst)
{
	t_stack	*tmp;

	tmp = (t_stack *)lst;
	while (tmp)
	{
		printf("%d\n", (tmp->num));
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		pivot;

	a = input_parse(ac, av);
	b = NULL;
	// printf("---------swap_a--------\n");
	// ps_swap(&a);
	// print_list(a);
	// printf("---------push_a--------\n");
	// ps_push(&a, &b);
	// print_list(a);
	// printf("---------push_b--------\n");
	// print_list(b);
	// printf("---------rotate_a--------\n");
	// ps_rotate(&a);
	// print_list(a);
	// printf("---------reverse_rotate_a--------\n");
	// ps_reverse(&a);
	// print_list(a);
	pivot = calculate_pivot(a);
	printf("%d", pivot);
	free_stack(a);
	free_stack(b);
	return (0);
}
