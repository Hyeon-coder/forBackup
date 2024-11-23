/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:26:48 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/11/23 17:45:32 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>   // open()
#include <stdio.h>

int	ft_strchr_pl(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (str[i] == c)
			return (i);
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char	str[BUFFER_SIZE + 1];
	int	i;

	read(fd, str, BUFFER_SIZE);
	i = ft_strchr_pl(str, '\n');
	remain = (char *)malloc(i * sizeof(char));
	if (!remain)
		return (NULL);
	remain[i] = '\0';
	while (--i)
	{
		remain[i] = str[i];
//		printf("\n------------\nremain : %c\tstr : %c\n------------\n", remain[i], str[i]);
		if (i == 1)
			printf("%s\n", remain);
	}
	printf("inside : %s\n", remain);
	return (remain);
}

int	main(void)
{
	int	fd;
	fd = open("./test.txt", O_RDONLY);
	printf("outside : %s\n", get_next_line(fd));
	return (0);
}

