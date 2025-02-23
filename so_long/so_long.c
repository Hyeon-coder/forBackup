/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:07:42 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/23 20:07:44 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	free_map(game);
	end_game(game, "Game closed.\n");
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	handle_input(keycode, game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error: Usage: ./so_long <map_file.ber>\n", 39);
		return (1);
	}
	init_game(&game, argv[1]);
	load_images(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
