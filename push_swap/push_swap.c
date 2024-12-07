/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:56:45 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/12/07 20:04:13 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_stack_push(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_stack_pop(t_list **lst, t_list *new)
{

}

void	push_swap(
