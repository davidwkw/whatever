/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:03:49 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:03:51 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_p_map(char ***ss_board, char obj, int p_x, int p_y)
{
	int	x;
	int	y;
	int	w;
	int	h;

	h = p_y + P_HEIGHT;
	w = p_x + P_WIDTH;
	y = p_y;
	while (y < h)
	{
		x = p_x;
		while (x < w)
		{
			if ((*ss_board)[y][x] == obj)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	is_oob(t_vars *mlx, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = mlx->img_cache.static_assets.width;
	map_y = mlx->img_cache.static_assets.height;
	return (x < 0 || y < 0 || x > map_x || y > map_y);
}
