/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:47:48 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/02/23 19:47:50 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_y < 0
		|| new_x >= game->width || new_y >= game->height)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E'
		&& game->collected == game->collectibles)
		end_game(game, "You won!\n");
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	printf("Moves: %d\n", game->moves);
	render_map(game);
}

void	handle_input(int key, t_game *game)
{
	if (key == 65307) // ESC
		end_game(game, "Game closed by user.\n");
	else if (key == 119 || key == 65362) // W or Up arrow
		move_player(game, 0, -1);
	else if (key == 115 || key == 65364) // S or Down arrow
		move_player(game, 0, 1);
	else if (key == 97 || key == 65361) // A or Left arrow
		move_player(game, -1, 0);
	else if (key == 100 || key == 65363) // D or Right arrow
		move_player(game, 1, 0);
}
