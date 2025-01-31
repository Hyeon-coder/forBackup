/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:14 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/15 10:45:51 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = input_parse(ac, av);
	b = NULL;
	if (ft_lstsize(a) <= 3)
		sort_three(&a);
	else
		quicksort_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
