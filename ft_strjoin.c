/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:39:38 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/01 19:20:39 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*rst;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	rst = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (rst == NULL)
		return (NULL);
	i = 0;
	while (i++ < len1)
		rst[i] = s1[i];
	len1 = 0;
	while (len1 < len2)
		rst[i++] = s2[len1++];
	rst[i] = '\0';
	return (rst);
}
