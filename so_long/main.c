/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:26 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/15 19:17:04 by juhyeonl         ###   ########.fr       */
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
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "./images/chest.xpm",
			&img_w, &img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./images/chest_open.xpm",
			&img_w, &img_h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./images/land.xpm",
			&img_w, &img_h);
	if (!game->img_wall || !game->img_player || !game->img_collectible
		|| !game->img_exit || !game->img_floor)
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

	// 🔹 기존 코드 (mlx_key_hook) → 변경 필요!
	// mlx_key_hook(game.win, handle_keypress, &game);

	// 🔹 수정된 코드 (mlx_hook 사용)
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, handle_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
