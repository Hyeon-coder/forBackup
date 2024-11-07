/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:49:52 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/05 12:15:06 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cp;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	cp = malloc((len + 1) * sizeof(char));
	if (!cp)
		return (NULL);
	while (s[i])
	{
		cp[i] = s[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
