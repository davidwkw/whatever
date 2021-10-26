/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:04:23 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:04:24 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	calc_w_cam(int win_width, int win_height, t_cam *cam)
{
	int	w_x_offset;
	int	w_y_offset;

	w_x_offset = 0 - cam->p_coords.x - (win_width / 2);
	w_y_offset = 0 - cam->p_coords.y - (win_height / 2);
	if (abs(w_x_offset) > win_width
		&& (abs(w_x_offset) - win_width) <= cam->max_x_offset)
		cam->w_coords.x = (abs(w_x_offset) - win_width) * -1;
	else if ((abs(w_x_offset) - win_width) > cam->max_x_offset)
		cam->w_coords.x = cam->max_x_offset * -1;
	if (abs(w_y_offset) > win_height
		&& (abs(w_y_offset) - win_height) <= cam->max_y_offset)
		cam->w_coords.y = (abs(w_y_offset) - win_height) * -1;
	else if ((abs(w_y_offset) - win_height) > cam->max_y_offset)
		cam->w_coords.y = cam->max_y_offset * -1;
}

static void	calc_p_cam(t_cam *cam)
{
	cam->p_coords.x += cam->w_coords.x;
	cam->p_coords.y += cam->w_coords.y;
}

static void	display_handler(t_vars *mlx, struct timeval *tv)
{
	unsigned long	delay;
	void			*p_img;

	mlx->cam.p_coords.x = mlx->player_state.coords.x - P_LEFT_OFFSET;
	mlx->cam.p_coords.y = mlx->player_state.coords.y - P_TOP_OFFSET;
	calc_w_cam(mlx->win_width, mlx->win_height, &mlx->cam);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->img_cache.static_assets.addr,
		mlx->cam.w_coords.x, mlx->cam.w_coords.y);
	display_info(mlx);
	delay = (tv->tv_sec - mlx->player_state.last_move_time.tv_sec) * 1000
		+ (tv->tv_usec - mlx->player_state.last_move_time.tv_usec) / 1000;
	if (delay < ANIM_TRANSITION)
		p_img = loop_run_player(&mlx->player_state,
				&mlx->img_cache.player, FPS);
	else
		p_img = loop_idle_player(&mlx->player_state,
				&mlx->img_cache.player, FPS);
	calc_p_cam(&mlx->cam);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		p_img, mlx->cam.p_coords.x, mlx->cam.p_coords.y);
	mlx->player_state.state++;
}

int	display(t_vars *mlx)
{
	struct timeval	tv;

	if (!modulate_fps(FPS))
		return (0);
	gettimeofday(&tv, NULL);
	display_handler(mlx, &tv);
	return (0);
}
