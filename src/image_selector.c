/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_selector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:04:09 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:04:10 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*select_idle_img(t_p_imgs *player, t_p_state *player_state, int state)
{
	if (player_state->direction == LEFT)
		return (player->m_player_idle[state].addr);
	else
		return (player->player_idle[state].addr);
}

void	*select_run_img(t_p_imgs *player, t_p_state *player_state, int state)
{
	if (player_state->direction == LEFT)
		return (player->m_player_run[state].addr);
	else
		return (player->player_run[state].addr);
}
