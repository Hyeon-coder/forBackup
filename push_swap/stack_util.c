/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:57:18 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/12/17 16:44:57 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack(char *nptr)
{
	t_stack	*n_node;
	int	data;

	data = ft_atoi(nptr);
	n_node = (t_stack *)malloc(sizeof(*n_node));
	if (!n_node)
		return (NULL);
	n_node->data = data;
	n_node->next = NULL;
	return (n_node);
}

void	stack_push(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

ft_switch()
{
	
}

ft_pop