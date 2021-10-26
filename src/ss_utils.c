/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:03:31 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:03:33 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	offset_p_top(t_coords *coords, char ***ss_board)
{
	int	x;
	int	y;
	int	p_x;
	int	p_y;

	p_x = coords->x;
	p_y = coords->y;
	y = -1;
	while (++y < P_TOP_OFFSET)
	{
		x = -1;
		while (++x < STATIC_OFFSET)
			(*ss_board)[p_y + y][p_x + x] = '0';
	}
}

static void	offset_p_left(t_coords *coords, char ***ss_board)
{
	int	x;
	int	y;
	int	p_x;
	int	p_y;

	p_x = coords->x;
	p_y = coords->y;
	y = -1;
	while (++y < STATIC_OFFSET)
	{
		x = -1;
		while (++x < P_LEFT_OFFSET)
			(*ss_board)[p_y + y][p_x + x] = '0';
	}
}

static void	offset_p_right(t_coords *coords, char ***ss_board)
{
	int	x;
	int	y;
	int	p_x;
	int	p_y;

	p_x = coords->x;
	p_y = coords->y;
	y = -1;
	while (++y < STATIC_OFFSET)
	{
		x = STATIC_OFFSET - P_RIGHT_OFFSET - 1;
		while (++x < STATIC_OFFSET)
			(*ss_board)[p_y + y][p_x + x] = '0';
	}
}

static void	offset_p_bottom(t_coords *coords, char ***ss_board)
{
	int	x;
	int	y;
	int	p_x;
	int	p_y;

	p_x = coords->x;
	p_y = coords->y;
	y = STATIC_OFFSET - P_IMG_HEIGHT - P_BOTTOM_OFFSET;
	while (++y < STATIC_OFFSET)
	{
		x = -1;
		while (++x < STATIC_OFFSET)
			(*ss_board)[p_y + y][p_x + x] = '0';
	}
}

void	super_sample_player(t_vars *mlx)
{
	offset_p_top(&mlx->player_state.coords, &mlx->ss_board);
	offset_p_left(&mlx->player_state.coords, &mlx->ss_board);
	offset_p_right(&mlx->player_state.coords, &mlx->ss_board);
	offset_p_bottom(&mlx->player_state.coords, &mlx->ss_board);
	mlx->player_state.coords.x += P_LEFT_OFFSET;
	mlx->player_state.coords.y += P_TOP_OFFSET;
}
