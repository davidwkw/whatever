/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:20:07 by kwang             #+#    #+#             */
/*   Updated: 2021/05/24 18:28:31 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			str_len;

	if (s)
	{
		str_len = ft_strlen(s);
		if (start < str_len)
		{
			if (len > str_len - start)
				len = str_len - start;
			substr = malloc(sizeof(char) * (len + 1));
			if (!substr)
				return (substr);
			i = -1;
			while (++i < len)
				substr[i] = s[start + i];
			substr[i] = '\0';
			return (substr);
		}
	}
	return (ft_strdup(""));
}
