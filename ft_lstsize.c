/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:45:00 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/11/05 15:36:59 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int			cnt;
	t_list		*tmp;

	tmp = (t_list *)lst;
	cnt = 0;
	while (tmp)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}
