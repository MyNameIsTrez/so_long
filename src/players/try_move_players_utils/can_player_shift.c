/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   can_player_shift.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:18:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:40:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sl_try_move_players_utils.h"

////////////////////////////////////////////////////////////////////////////////

bool	can_player_shift(t_player *player, size_t movement_key_index,
			t_data *data)
{
	keys_t	key;
	t_i32	frames_held;
	bool	key_was_held;

	key = player->controls.movement_keys[movement_key_index];
	if (!mlx_is_key_down(data->mlx, key))
		return (false);
	frames_held = data->held_keys[key];
	key_was_held = frames_held > 0;
	if (key_was_held && !can_autowalk(player, data))
		return (false);
	if (!is_walkable(player, key, data))
		return (false);
	return (true);
}

////////////////////////////////////////////////////////////////////////////////
