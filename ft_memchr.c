/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:03:53 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/10/31 11:40:15 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp;
	unsigned char		target;

	tmp = (const unsigned char *)s;
	target = (unsigned char)c;
	while (n > 0)
	{
		if (*tmp == target)
			return ((char *)tmp);
		tmp++;
		n--;
	}
	return (0);
}
