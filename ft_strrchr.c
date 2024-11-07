/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:36:44 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/11/05 12:07:54 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (c == '\0')
		return ((char *)(&s[i]));
	i -= 1;
	while (i != 0)
	{
		if (s[i] == c)
			return ((char *)(&s[i]));
		i--;
	}
	return (0);
}
