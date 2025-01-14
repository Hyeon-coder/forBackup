/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:14:40 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/01/14 12:11:19 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_reverse(t_stack **lst)
{
	t_stack	*last;
	t_stack	*second_last;

	if ((*lst)->size > 1)
	{
		last = *lst;
		second_last = NULL;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		if (second_last)
			second_last->next = NULL;
		last->next = *lst;
		*lst = last;
	}
}

void	rra(t_stack **lst, int flag)
{
	ps_reverse(lst);
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **lst, int flag)
{
	ps_reverse(lst);
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **lst, t_stack **lst2)
{
	rra(lst, 0);
	rrb(lst2, 0);
	write(1, "rrr\n", 4);
}