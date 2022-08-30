/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trying_to_move.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:18:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 11:47:47 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "trying_to_move/sl_private_trying_to_move.h"

////////////////////////////////////////////////////////////////////////////////

bool	trying_to_move(t_player *player, t_data *data)
{
	keys_t	key;
	t_i32	frames_held;

	key = player->controls.movement_keys[data->it.heading];
	frames_held = data->held_keys[key];
	return (frames_held == 1
		|| (frames_held > 1 && can_autowalk(player, data)));
}

////////////////////////////////////////////////////////////////////////////////
