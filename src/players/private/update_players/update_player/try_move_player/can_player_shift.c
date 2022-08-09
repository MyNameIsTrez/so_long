/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   can_player_shift.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:18:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 20:33:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "can_player_shift/sl_private_can_player_shift.h"

////////////////////////////////////////////////////////////////////////////////

bool	can_player_shift(t_player *player, t_heading heading, t_data *data)
{
	keys_t	key;
	t_i32	frames_held;
	bool	key_was_held;

	key = player->controls.movement_keys[heading];
	frames_held = data->held_keys[key];
	if (frames_held == 0)
		return (false);
	key_was_held = frames_held > 1;
	if (key_was_held && !can_autowalk(player, data))
		return (false);
	if (!is_walkable(player, heading, data))
		return (false);
	return (true);
}

////////////////////////////////////////////////////////////////////////////////
