/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:04:01 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:04:03 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		printf("Usage: %s [<MAP_NAME>.ber]\n", argv[0]);
	parse_map(argv[1], &map);
	mlx_handler(&map);
	return (0);
}
