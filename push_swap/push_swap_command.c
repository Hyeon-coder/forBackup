/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:00:54 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/01/10 17:10:41 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;
	
	if ((*lst)->size > 1)
	{
		first = stack_pop(lst);
		second = stack_pop(lst);
		stack_push(lst, first);
		stack_push(lst, second);
	}
}

void	ps_push(t_stack **lst, t_stack **dst)
{
	t_stack	*tmp;
		
	if ((*lst)->size > 1)
	{
		tmp = stack_pop(lst);
		stack_push(dst, tmp);
	}
}

void	ps_rotate(t_stack **lst)
{
	t_stack	*tmp;
	
	if ((*lst)->size > 1)
	{
		tmp = stack_pop(lst);
		ft_lstadd_back(lst, tmp);
	}
}

void	ps_reverse(t_stack **lst)
{
	t_stack *last;
	t_stack *second_last;

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
