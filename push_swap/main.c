/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:06:15 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/12/17 15:58:16 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main (int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	i;
	
	if (argc < 2)
		return (0);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (i == 1)
				a = ft_stack(argv[i]);
			else
				stack_push(&a, ft_stack(argv[i]));
			i++;
		}
		print_result(a, b);
		print_list(a);	// remove
	}
	return (0);
}