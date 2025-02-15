/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:41:42 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/15 19:17:46 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 65307)
		exit(0);
	else if (keycode == 119 || keycode == 65362) // W키 or ↑ 방향키
		new_y -= 1;
	else if (keycode == 115 || keycode == 65364) // S키 or ↓ 방향키
		new_y += 1;
	else if (keycode == 97 || keycode == 65361) // A키 or ← 방향키
		new_x -= 1;
	else if (keycode == 100 || keycode == 65363) // D키 or → 방향키
		new_x += 1;
	if (game->map[new_y][new_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0'; // 기존 자리 초기화
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P'; // 새 위치 설정
		render_map(game);
	}
	return (0);
}

