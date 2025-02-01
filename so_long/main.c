/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:19:31 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/01 12:39:30 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"

int	main()
{
	void	*mlx;
	void	*win;
	int		x = 250;
	int		y = 250;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Test Window");
	while (x < 500)
		mlx_pixel_put(mlx, win, x--, y--, 0xFF0000);
	mlx_loop(mlx);
	return (0);
}