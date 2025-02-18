/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:26 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/18 15:52:12 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./images/wall.xpm",
			&img_w, &img_h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./images/chara.xpm",
			&img_w, &img_h);
	game->img_collectible_before = mlx_xpm_file_to_image(game->mlx, "./images/chest.xpm",
			&img_w, &img_h);
	game->img_collectible_after = mlx_xpm_file_to_image(game->mlx, "./images/chest_open.xpm",
			&img_w, &img_h);
	game->img_exit_close = mlx_xpm_file_to_image(game->mlx, "./images/rune.xpm",
			&img_w, &img_h);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx, "./images/rune_light.xpm",
			&img_w, &img_h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./images/land.xpm",
			&img_w, &img_h);
	if (!game->img_wall || !game->img_player || !game->img_collectible_after
		|| !game->img_collectible_before || !game->img_exit_close
		|| !game->img_exit_open || !game->img_floor)
	{
		ft_putstr_fd("Error: Failed to load one or more images\n", 2);
		exit(1);
	}
}

void	init_map(t_game *game, char *map_file)
{
	game->map = read_map(map_file, &game->width, &game->height);
	if (!game->map)
	{
		ft_putstr_fd("Error: Failed to read the map\n", 2);
		exit(1);
	}
	if (!validate_map(game))
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		free_map(game->map, game->height);
		exit(1);
	}
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error: Failed to initialize MiniLibX\n", 2);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		ft_putstr_fd("Error: Failed to create window\n", 2);
		exit(1);
	}
}

int	handle_exit(t_game *game)
{
    (void)game;
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Please provide a map file (.ber)\n", 2);
		return (1);
	}
	init_map(&game, argv[1]);
	init_window(&game);
	load_images(&game);
	render_map(&game);
	game.moves = 0;
	write(1, "moves : ", 8);
	ft_putnbr_fd(game.moves, 1);
	write(1, "\n", 1);
	write(1, "collectibles : ", ft_strlen("collectibles : "));
	ft_putnbr_fd(game.collectibles, 1);
	write(1, "\n", 1);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, handle_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
