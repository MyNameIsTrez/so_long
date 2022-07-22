/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement_keys.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 12:08:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 17:39:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_player_movement_keys(
								t_player *player, t_data *data, bool reset)
{
	static keys_t	player_movement_key_index;
	keys_t			*movement_keys;

	if (reset)
	{
		player_movement_key_index = 0;
		data->it.player_movement_key = 0;
		return (RESET);
	}
	movement_keys = player->controls.movement_keys;
	while (player_movement_key_index < 4)
	{
		data->it.player_movement_key = movement_keys[player_movement_key_index];
		player_movement_key_index++;
		return (LOOPED);
	}
	sl_reset_iterate_player_movement_keys(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_player_movement_keys(t_player *player,
			t_data *data)
{
	return (resettable_iterate_player_movement_keys(player, data, false));
}

void	sl_reset_iterate_player_movement_keys(t_data *data)
{
	resettable_iterate_player_movement_keys(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
