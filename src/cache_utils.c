/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:04:32 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:04:36 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cache_image(void *mlx, t_data *img, char *path)
{
	img->addr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->img = mlx_get_data_addr(img->addr, &img->bpp,
			&img->size_line, &img->endian);
}

void	cache_mirror_image(void *mlx, t_data *img, t_data *mirror)
{
	int		w;
	int		h;
	int		*dst;
	int		*src;

	mirror->addr = mlx_new_image(mlx, img->width, img->height);
	mirror->height = img->height;
	mirror->width = img->width;
	mirror->img = mlx_get_data_addr(mirror->addr, &mirror->bpp,
			&mirror->size_line, &mirror->endian);
	src = (int *)img->img;
	dst = (int *)mirror->img;
	h = -1;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
			dst[w + (h * (mirror->size_line / (mirror->bpp / 8)))]
				= src[(img->size_line / (img->bpp / 8)) - 1
				+ (h * (img->size_line / (img->bpp / 8))) - w];
	}
}

void	cache_shadow(t_data *obj, t_data *shadow)
{
	int	w;
	int	h;
	int	*dst;
	int	*src;

	src = (int *)obj->img;
	dst = (int *)shadow->img;
	h = -1;
	while (++h < obj->height)
	{
		w = -1;
		while (++w < obj->width)
		{
			if (src[w + (h * (obj->size_line / (obj->bpp / 8)))] == TRANS_P)
				dst[w + (h * (shadow->size_line / (shadow->bpp / 8)))]
					= TRANS_P;
		}
	}
}
