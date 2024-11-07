/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:50:05 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/07 12:19:59 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*tmp;

	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, tmp);
		lst = lst->next;
	}
	return (nlst);
}
