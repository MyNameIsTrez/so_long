/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   can_autowalk.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:18:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:40:14 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	can_autowalk(t_player *player, t_data *data)
{
	t_i32	frames_held;
	bool	held_long_enough;
	bool	is_autowalk_frame;

	while (sl_iterate_player_movement_keys(player, data) != FINISHED)
	{
		frames_held = data->held_keys[data->it.player_movement_key];
		held_long_enough = frames_held >= MIN_FRAMES_HELD_FOR_AUTOWALK;
		is_autowalk_frame = frames_held % FRAMES_BETWEEN_AUTOWALK == 0;
		if (held_long_enough && is_autowalk_frame)
		{
			sl_reset_iterate_player_movement_keys(data);
			return (true);
		}
	}
	return (false);
}

////////////////////////////////////////////////////////////////////////////////
