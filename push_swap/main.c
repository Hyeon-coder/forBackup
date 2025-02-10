/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:14 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/07 16:18:48 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**numbers;
	t_stack	*a;
	t_stack	*b;

	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		a = input_parse((int)ft_countword(av[1], ' '), numbers, 1);
		b = NULL;
	}
	else
	{
		a = input_parse(ac, av, 0);
		b = NULL;
	}
	if (ft_lstsize(a) <= 3)
		sort_three(&a);
	else
		quicksort_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
