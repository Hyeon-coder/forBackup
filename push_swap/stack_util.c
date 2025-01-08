/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:57:18 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/01/08 15:52:10 by juhyeonl         ###   ########.fr       */
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

t_stack	*stack_pop(t_stack *lst)
{
	lst = lst->next;
	return (lst);
}

char	*stack_peek(t_stack *lst)
{
	return (lst->data);
}

t_stack	*ft_stack(char *nptr)
{
	t_stack	*n_node;
	
	n_node = (t_stack *)malloc(sizeof(*n_node));
	if (!n_node)
		return (NULL);
	n_node->data = nptr;
	n_node->next = NULL;
	return (n_node);
}
