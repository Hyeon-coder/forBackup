/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:23:12 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/07 12:13:15 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = (t_list *)lst;
	if (tmp && f)
	{
		while (tmp)
		{
			f(tmp->content);
			tmp = tmp->next;
		}
	}
}
