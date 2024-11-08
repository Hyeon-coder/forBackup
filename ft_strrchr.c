/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:36:44 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/11/08 00:53:04 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i = (char*)s;
		++s;
	}
	if (i)
		return (i);
	if (!c)
		return ((char*)s);
	return (0);
}
