/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:11:37 by juhyeonl          #+#    #+#             */
/*   Updated: 2024/11/23 12:45:23 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(void)
{
	char	*str1 = "Hello";
	char	*str2 = ", ";
	char	*str3 = "World";
	char	*rst;
}
