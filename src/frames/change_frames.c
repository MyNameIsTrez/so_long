/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_frames.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 13:28:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 17:11:49 by sbos          ########   odam.nl         */
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
	size_t		frame_count;

	ft_init_it(&it);
	while (sl_iterate_entities(&it, data) != FINISHED)
	{
		entity = data->it.entity;
		if (!entity->enabled)
			continue ;
		if (entity->ticks_since_last_frame_change > \
			entity->ticks_between_frame_changes)
		{
			tile = &entity->tile;
			sl_get_frame_instance(tile, tile->frame_index)->enabled = false;
			frame_count = tile->tile_kind->frame_count;
			tile->frame_index = (tile->frame_index + 1) % frame_count;
			sl_get_frame_instance(tile, tile->frame_index)->enabled = true;
			entity->ticks_since_last_frame_change = 0;
		}
		else
			entity->ticks_since_last_frame_change++;
		// TODO: Do something fun with varying frame rates during gameplay
		// entity->ticks_between_frame_changes -= 0.001;
	}
}

////////////////////////////////////////////////////////////////////////////////
