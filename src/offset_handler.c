/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:03:47 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:03:48 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_top_bottom(int *img_data, t_data *img, t_offsets *offset)
{
	int	w;
	int	h;
	int	value;

	h = -1;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
		{
			value = img_data[(h * img->size_line / (img->bpp / 8)) + w];
			if (!offset->top && value != TRANS_P)
			{
				offset->top = h;
				offset->bottom = h;
			}
			else if (value != TRANS_P && h > offset->bottom)
				offset->bottom = h;
		}
	}
}

static void	set_left_right(int *img_data, t_data *img, t_offsets *offset)
{
	int	w;
	int	h;
	int	value;

	w = -1;
	while (++w < img->width)
	{
		h = -1;
		while (++h < img->height)
		{
			value = img_data[(h * img->size_line / (img->bpp / 8)) + w];
			if (!offset->left && value != TRANS_P)
			{
				offset->left = w;
				offset->right = w;
			}
			else if (value != TRANS_P && w > offset->right)
				offset->right = w;
		}
	}
}

void	calc_offsets(t_data *img, t_offsets *offset)
{
	int	*img_data;

	img_data = (int *)img->img;
	set_top_bottom(img_data, img, offset);
	set_left_right(img_data, img, offset);
}
