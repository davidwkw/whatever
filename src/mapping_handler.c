/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:03:54 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:03:55 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_player(char ***ss_board, int p_x, int p_y, char c)
{
	int	w;
	int	h;
	int	x;
	int	y;

	w = p_x + P_WIDTH;
	h = p_y + P_HEIGHT;
	y = p_y;
	while (y < h)
	{
		x = p_x;
		while (x < w)
		{
			(*ss_board)[y][x] = c;
			x++;
		}
		y++;
	}
}

void	map_tile(char ***ss_board, int origin_x, int origin_y, char c)
{
	int	w;
	int	h;
	int	x;
	int	y;

	w = origin_x + STATIC_OFFSET;
	h = origin_y + STATIC_OFFSET;
	y = origin_y;
	while (y < h)
	{
		x = origin_x;
		while (x < w)
		{
			(*ss_board)[y][x] = c;
			x++;
		}
		y++;
	}
}

void	locate_p_collision(t_vars *mlx, int *coll_x, int *coll_y, char c)
{
	int	x;
	int	y;
	int	w;
	int	h;

	h = mlx->player_state.coords.y + P_HEIGHT;
	w = mlx->player_state.coords.x + P_WIDTH;
	y = mlx->player_state.coords.y;
	while (y < h)
	{
		x = mlx->player_state.coords.x;
		while (x < w)
		{
			if (mlx->ss_board[y][x] == c)
			{
				*coll_x = x;
				*coll_y = y;
			}
			x++;
		}
		y++;
	}
}
