/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:06:15 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/12/19 15:55:47 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	stack_pop(t_stack *lst)
{
	lst = lst->next;
}

int	main (int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	if (argc < 2)
		return (0);
	else
	{
		i = 0;
		while (++i < argc)
		{
			if (i == 1)
				a = ft_stack(argv[i]);
			else
				stack_push(&a, ft_stack(argv[i]));
		}
		b = ft_stack(NULL);
		ft_move(a, b);
	}
	return (0);
}