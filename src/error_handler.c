/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:04:13 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:04:15 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handler(char *msg, char *func, int err_no)
{
	if (err_no)
		errno = err_no;
	printf("Error\n");
	printf("%s\n", msg);
	perror(func);
	exit(EXIT_FAILURE);
}
