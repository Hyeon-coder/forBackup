/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:39:38 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/08 14:50:25 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*rst;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	rst = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!rst)
		return (NULL);
	if (s1 && s2)
	{
		i = -1;
		while (s1[++i])
			rst[i] = s1[i];
		while (s2[++i])
		{
			rst[len1] = s2[i];
			len1++;
		}
		rst[len1] = '\0';
	}
	else if (!s1 && s2)
	{
		while (s2
	}
	else if (s1 && !s2)
	{

	}
	else
	{
		return (NULL)
	}
	
	return (rst);
}
