/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:04:27 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:04:29 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collection_handler(t_vars *mlx)
{
	int	coll_x;
	int	coll_y;

	locate_p_collision(mlx, &coll_x, &coll_y, 'C');
	map_tile(&mlx->ss_board, (coll_x / 100) * 100, (coll_y / 100) * 100, '0');
	render_tile(&mlx->img_cache.static_assets,
		coll_x / 100, coll_y / 100, &mlx->img_cache.bg);
	mlx->map->collectible--;
}
