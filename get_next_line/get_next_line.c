/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:26:48 by JuHyeon           #+#    #+#             */
/*   Updated: 2024/12/11 14:31:21 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buffer(int fd, char*buff)
{
	int	rd_byte;

	rd_byte = read(fd, buff, BUFFER_SIZE);
	if (rd_byte == -1)
		return (NULL);
	buff[rd_byte] = '\0';
	if (rd_byte == 0)
		return (NULL);
	else
		return (buff);
}

char	*ft_left_str(int fd, char *left)
{
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(left, '\n'))
	{
		if (!ft_read_buffer(fd, buff))
		{
			free(buff);
			return (NULL);
		}
		left = ft_strjoin(left, buff);
		if (!left)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (left);
}

char	*ft_new_left_str(char *left)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left[i])
		str[j++] = left[i++];
	str[j] = '\0';
	free(left);
	return (str);
}

char	*ft_get_line(char *left)
{
	char	*str;
	int		i;

	i = 0;
	if (!left || !left[i])
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		str[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		str[i] = left[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left = ft_left_str(fd, left);
	if (!left)
		return (NULL);
	line = ft_get_line(left);
	left = ft_new_left_str(left);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	char *line1;
	char *line2;
	char *line3;
	int fd1;
	int	fd2;
	int	fd3;
	int i;

	fd1 = open("./test.txt", O_RDONLY);
	fd2 = open("./test2.txt", O_RDONLY);
	fd3 = open("./test3.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0) {
		perror("Failed to open file");
		return 1;
	}
	i = 1;
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	while (i < 4) {
		printf("line [%d]: %s", i, line1);
		printf("line [%d]: %s", i, line2);
		printf("line [%d]: %s", i, line3);
		i++;
	}
	free(line1);
	free(line2);
	free(line3);
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}
