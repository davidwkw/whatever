/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:43:24 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 16:43:30 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lst_to_arr(t_list *lst)
{
	void	**arr;
	int		i;
	int		count;

	count = ft_lstsize(lst);
	arr = malloc(sizeof(void *) * (count + 1));
	i = 0;
	while (lst)
	{
		arr[i++] = lst->content;
		lst = lst->next;
	}
	arr[i] = NULL;
	return (arr);
}
