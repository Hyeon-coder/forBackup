/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:41:18 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/18 15:55:51 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validate_map(t_game *game)
{
    int x, y;
    int has_player = 0;
    int has_exit = 0;

    for (y = 0; y < game->height; y++)
    {
        for (x = 0; x < game->width; x++)
        {
            if (game->map[y][x] == 'P')
            {
                has_player = 1;
                game->player_x = x;
                game->player_y = y;
            }
            else if (game->map[y][x] == 'E')
                has_exit = 1;
        }
    }
    return (has_player && has_exit);
}
