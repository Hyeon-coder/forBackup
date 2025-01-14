/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:14 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/14 12:15:06 by juhyeonl         ###   ########.fr       */
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
	pivot = calculate_pivot(a);
	printf("\nIn the main >> pivot >>> %d\n\n", pivot);
	printf("-----a------\n");
	print_list(a);
	printf("------b------\n\n--------------\n");
	print_list(b);
	if (ac <= 4)
		sort_three(&a);
	else if (ac <= 6)
		sort_five(&a, &b);
	else
		quicksort_stack(&a, &b, a->size);
	printf("------a------\n");
	print_list(a);
	printf("------b------\n");
	print_list(b);
	free_stack(a);
	free_stack(b);
	return (0);
}
