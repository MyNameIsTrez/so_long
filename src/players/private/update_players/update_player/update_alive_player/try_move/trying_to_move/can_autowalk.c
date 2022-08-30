/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   can_autowalk.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:18:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 17:00:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	can_autowalk(t_player *player, t_data *data)
{
	keys_t	key;
	t_i32	frames_held;
	bool	held_long_enough;
	bool	is_autowalk_frame;

	key = player->controls.movement_keys[data->it.heading];
	frames_held = data->held_keys[key];
	held_long_enough = frames_held >= MIN_FRAMES_HELD_FOR_AUTOWALK;
	is_autowalk_frame = frames_held % FRAMES_BETWEEN_AUTOWALK == 0;
	return (held_long_enough && is_autowalk_frame);
}

////////////////////////////////////////////////////////////////////////////////
