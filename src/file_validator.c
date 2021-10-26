/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:04:11 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:04:12 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_file_ext(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext || ext == filename)
		return (NULL);
	return (ext + 1);
}

void	check_valid_ext(char *filename, char *ext_to_check)
{
	size_t	ext_len;
	size_t	check_len;
	char	*ext;

	ext = get_file_ext(filename);
	if (!ext)
		error_handler("Absent file extension", "check_valid_ext", EIO);
	ext_len = ft_strlen(ext);
	check_len = ft_strlen(ext_to_check);
	if (ext_len != check_len || ft_strncmp(ext, ext_to_check, check_len))
		error_handler("Wrong file extension", "check_valid_ext", EIO);
}
