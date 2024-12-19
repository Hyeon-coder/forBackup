/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:57:18 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/12/19 15:58:14 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_switch()
{
	
}

void	ft_move(t_stack *src, t_stack *dst)
{
	if (dst->data != NULL)
		dst = ft_stack(src->data);
	else
		stack_push(&dst, ft_stack(src->data));
	src = src->next;
	printf("------a------\n");
	print_list(src);
	printf("------b------\n");
	print_list(dst);
}

void	ft_rotate()
{
	
}

void	ft_revers_rotate()
{
	
}