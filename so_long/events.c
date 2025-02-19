/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:41:42 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/18 14:02:02 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// W or ↓ == 119 or 65362
// S or ↓ == 115 or 65364
// A or ← == 97 or 65361
// D or → == 100 or 65363

#include "so_long.h"

void	move_count(t_game *game)
{
	game->moves += 1;
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 65307)
		exit(0);
	else if (keycode == 119 || keycode == 65362)
		new_y -= 1;
	else if (keycode == 115 || keycode == 65364)
		new_y += 1;
	else if (keycode == 97 || keycode == 65361)
		new_x -= 1;
	else if (keycode == 100 || keycode == 65363)
		new_x += 1;        
	if (game->map[new_y][new_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P';
		render_map(game);
	}
	move_count(game);
	return (0);
}

