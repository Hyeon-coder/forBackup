/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:03:01 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/01/13 06:57:58 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
	if (*lst)
	{
		if ((*lst)->next)
			(*lst)->size = (*lst)->next->size + 1;
		else
			(*lst)->size = 1;
	}
}

t_stack	*stack_pop(t_stack **lst)
{
	t_stack	*popped_node;

	if (!lst || !*lst)
		return (NULL);
	popped_node = *lst;
	*lst = (*lst)->next;
	if (*lst)
		(*lst)->size = popped_node->size - 1;
	popped_node->next = NULL;
	return (popped_node);
}

int	stack_peek(t_stack *lst)
{
	return (lst->num);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
