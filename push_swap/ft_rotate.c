/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:14:38 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/01/15 08:52:56 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate(t_stack **lst)
{
	t_stack	*tmp;

	if (ft_lstsize(*lst) > 1)
	{
		tmp = stack_pop(lst);
		ft_lstadd_back(lst, tmp);
	}
}

void	ra(t_stack **lst, int flag)
{
	ps_rotate(lst);
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack **lst, int flag)
{
	ps_rotate(lst);
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack **lst, t_stack **lst2)
{
	ra(lst, 0);
	rb(lst2, 0);
	write(1, "rr\n", 3);
}