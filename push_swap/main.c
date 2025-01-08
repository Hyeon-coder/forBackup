/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:06:15 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/01/08 16:39:37 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *lst)
{
	t_stack	*tmp;

	tmp = (t_stack *)lst;
	while (tmp)
	{
		printf("%s\n", (tmp->data));
		tmp = tmp->next;
	}
}
/* TODO
make input_parse
make command(ex. pa pb ...)
make algorithm
*/
int	main (int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	if (input_parse(ac, av))	// TODO
	{
		write(1, "Error", 5);
		return (0);
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			if (i == 1)
				a = ft_stack(av[i]);
			else
				stack_push(&a, ft_stack(av[i]));
		}
		b = ft_stack(NULL);
		ft_move(a, b);
	}
	char	*tmp;
	printf("------peek------\n");
	tmp = stack_peek(a);
	printf("%s\n", tmp);
	printf("------a------\n");
	print_list(a);
	printf("------peek------\n");
	printf("------pop------\n");
	a = stack_pop(a);
	printf("------a------\n");
	print_list(a);
	printf("------pop------\n");
	printf("------push------\n");
	stack_push(&a, ft_stack(tmp));
	printf("------a------\n");
	print_list(a);
	printf("------push------\n");
	return (0);
}