/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:41:02 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/15 16:47:54 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(char *filename, int *width, int *height)
{
    int fd;
    char *line;
    char **map;
    int row = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);

    map = malloc(sizeof(char *) * 100); // 최대 100줄 (예제)
    if (!map)
        return (NULL);

    while ((line = get_next_line(fd)))
    {
        map[row++] = line;
    }
    map[row] = NULL;
    *height = row;
    *width = (row > 0) ? (int)ft_strlen(map[0]) - 1 : 0;
    close(fd);
    return (map);
}
