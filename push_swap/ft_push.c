/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:14:47 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/01/15 08:54:36 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push(t_stack **lst, t_stack **dst)
{
	t_stack	*tmp;

	if (ft_lstsize(*lst) >= 1)
	{
		tmp = stack_pop(lst);
		
		stack_push(dst, tmp);
	}
}

void	pa(t_stack **lst, t_stack **dst)
{
	ps_push(lst, dst);
	printf("pa\n");
}

void	pb(t_stack **lst, t_stack **dst)
{
	ps_push(lst, dst);
	printf("pb\n");
}