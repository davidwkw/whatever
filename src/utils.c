/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:03:26 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:03:28 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	modulate_fps(int fps)
{
	struct timeval			tv;
	static struct timeval	prev;

	gettimeofday(&tv, NULL);
	if (tv.tv_sec == prev.tv_sec
		&& (tv.tv_usec - prev.tv_usec) < (1000000 / fps))
		return (0);
	prev = tv;
	return (1);
}

void	display_info(t_vars *mlx)
{
	char				*steps_str;
	char				*steps;
	char				*coll_str;
	char				*num_coll;

	steps = ft_itoa(mlx->total_steps);
	steps_str = ft_strjoin("Total steps : ", steps);
	mlx_string_put(mlx->mlx, mlx->win, 20,
		mlx->win_height - 15, 0x00FFFFFF, steps_str);
	num_coll = ft_itoa(mlx->map->collectible);
	coll_str = ft_strjoin("Collectibles : ", num_coll);
	mlx_string_put(mlx->mlx, mlx->win, 220,
		mlx->win_height - 15, 0x00FFFFFF, coll_str);
	free(steps);
	free(steps_str);
	free(coll_str);
	free(num_coll);
}

int	exit_program(t_vars *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}
