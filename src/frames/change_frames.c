/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_frames.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 13:28:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 20:47:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_change_frames(t_data *data)
{
	t_iterator	it;
	t_entity	*entity;
	t_tile		*tile;
	t_f64		seconds_elapsed;
	size_t		frame_count;

	while (sl_iterate_entities(&it, data) != FINISHED)
	{
		entity = data->it.entity;
		seconds_elapsed = data->seconds - entity->seconds_since_last_frame_change;
		if (seconds_elapsed > entity->seconds_between_frame_changes)
		{
			tile = &entity->tile;
			sl_get_frame_instance(tile, tile->frame_index)->enabled = false;
			frame_count = tile->tile_kind->frame_count;
			tile->frame_index = (tile->frame_index + 1) % frame_count;
			sl_get_frame_instance(tile, tile->frame_index)->enabled = true;
			entity->seconds_since_last_frame_change = data->seconds;
		}
		// TODO: Do something with varying frame rates during gameplay
		// entity->seconds_between_frame_changes -= 0.001;
	}
}

////////////////////////////////////////////////////////////////////////////////
