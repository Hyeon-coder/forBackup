/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:33:10 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/01/08 15:38:58 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	ft_rotate()
{
	
}

void	ft_revers_rotate()
{
	
}