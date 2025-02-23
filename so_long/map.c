/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:50:17 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/23 19:53:10 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map_dimensions(t_game *game, char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		end_game(game, "Error: Failed to open map file.\n");
	game->width = 0;
	game->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (game->width == 0)
			game->width = ft_strlen(line) - 1;
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	load_map(t_game *game, char *map_file)
{
	int	fd;
	int	i;

	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		end_game(game, "Error: Memory allocation failed.\n");
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		end_game(game, "Error: Failed to open map file.\n");
	i = 0;
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	game->map[game->height] = NULL;
	close(fd);
}

void	init_game(t_game *game, char *map_file)
{
	game->mlx = mlx_init();
	count_map_dimensions(game, map_file);
	load_map(game, map_file);
	check_map_validity(game);
}
