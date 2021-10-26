/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:03:59 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:04:00 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_valid_map(t_map *map)
{
	size_t	y;

	map->size_x = ft_strlen(map->board[0]);
	map->size_y = arr_len(map->board);
	y = 0;
	while (map->board[y])
	{
		if (y == 0 || y == map->size_y - 1)
			check_tb_border(map->board[y]);
		if (map->size_x != ft_strlen(map->board[y]))
			error_handler("Invalid map shape", "is_valid_map", EIO);
		check_map_content(map->board[y], map, y);
		y++;
	}
	if (!map->collectible || !map->exit || !map->player)
		error_handler("Insufficient map content", "check_map_content", EIO);
}

static void	cache_map(int fd, t_map *map)
{
	char	*line;
	t_list	*head;
	t_list	*lst;

	head = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (errno)
			error_handler("Read error", "cache_map", EIO);
		lst = ft_lstnew(line);
		if (!lst->content)
			error_handler("Str duplicate error", "cache_map", EIO);
		ft_lstadd_back(&head, lst);
	}
	map->board = (char **)ft_lst_to_arr(head);
	ft_lstclear(&head, NULL);
	free(line);
}

void	parse_map(char *filename, t_map *map)
{
	int		fd;

	check_valid_ext(filename, "ber");
	*map = (t_map){.board = NULL};
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_handler("Open file failure", "is_valid_map", 0);
	cache_map(fd, map);
	close(fd);
	is_valid_map(map);
}
