/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:06:15 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/12/07 20:36:39 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	if (argc < 2)
		return 0;
	i = 1;
	while (i < argc)
	{
		ft_valid_check(argv[i]);
		ft_stack_push(argv[i]);
	}
	return (0);
}
