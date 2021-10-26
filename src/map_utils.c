/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:03:56 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:03:58 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_side_border(char c)
{
	if (c != '1')
		error_handler("Vertical border not intact", "check_side_border", EIO);
}

void	parse_map_items(char c, t_map *map, int x, int y)
{
	if (c == 'P')
	{
		map->player++;
		if (map->player > 1)
			error_handler("More than 1 player", "parse_map_items", EIO);
		map->player_coords.x = x;
		map->player_coords.y = y;
	}
	else if (c == 'C')
		map->collectible++;
	else if (c == 'E')
		map->exit++;
}

void	check_tb_border(char *line)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] != '1')
			error_handler("Invalid horizontal border", "check_tb_border", EIO);
		i++;
	}
}

void	check_map_content(char *line, t_map *map, size_t y)
{
	size_t	x;

	x = 0;
	while (line[x])
	{
		if (x == 0 || x == (ft_strlen(line) - 1))
			check_side_border(line[x]);
		else if (ft_strchr("01CEP", line[x]))
			parse_map_items(line[x], map, x, y);
		else
			error_handler("Invalid map item", "check_map_content", EIO);
		x++;
	}
}
