/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:03:41 by kwang             #+#    #+#             */
/*   Updated: 2021/10/26 17:03:43 by kwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*loop_run_player(t_p_state *player_state, t_p_imgs *player, int fps)
{
	unsigned int	state;
	unsigned int	frames;
	void			*p_img_addr;

	frames = sizeof(player->player_run) / sizeof(*player->player_run);
	state = player_state->state / (fps / frames);
	p_img_addr = select_run_img(player, player_state, state % frames);
	if (state == frames)
		player_state->state = 0;
	return (p_img_addr);
}

void	*loop_idle_player(t_p_state *player_state, t_p_imgs *player, int fps)
{
	unsigned int	state;
	unsigned int	frames;
	void			*p_img_addr;

	frames = sizeof(player->player_idle) / sizeof(*player->player_idle);
	state = player_state->state / (fps / frames);
	p_img_addr = select_idle_img(player, player_state, state % frames);
	if (state == frames)
		player_state->state = 0;
	return (p_img_addr);
}
