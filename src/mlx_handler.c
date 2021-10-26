/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:03:52 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:03:53 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_handler(t_map *map)
{
	t_vars	mlx;

	mlx = (t_vars){};
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		error_handler("Display var not configured", "main", EIO);
	mlx.map = map;
	init_window_var(&mlx, mlx.map);
	init_images(&mlx, mlx.mlx, &mlx.img_cache);
	init_player_state(&mlx.player_state, mlx.map, &mlx.img_cache.player);
	super_sample_board(&mlx);
	init_cam(&mlx, &mlx.cam, &mlx.img_cache.static_assets);
	printf("Total Steps : %d\n", mlx.total_steps);
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_width, mlx.win_height, "So_long");
	mlx_key_hook(mlx.win, key_handler, &mlx);
	mlx_loop_hook(mlx.mlx, display, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_program, &mlx);
	mlx_loop(mlx.mlx);
}
