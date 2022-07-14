/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frames_byte_indices.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 12:42:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 13:08:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frames_byte_indices(
			t_tile_kind *tile_kind, t_data *data, bool reset)
{
	if (reset)
	{
		sl_reset_iterate_frames(data);
		sl_reset_iterate_frame_byte_indices(data);
		return (RESET);
	}
	while (true)
	{
		if (data->it.frame == NULL)
			sl_iterate_frames(tile_kind, data);
		while (true)
		{
			if (sl_iterate_frame_byte_indices(data->it.frame, data) != LOOPED)
				break ;
			return (LOOPED);
		}
		sl_reset_iterate_frame_byte_indices(data);
		if (sl_iterate_frames(tile_kind, data) != LOOPED)
			break ;
	}
	sl_reset_iterate_frames_byte_indices(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frames_byte_indices(t_tile_kind *tile_kind,
			t_data *data)
{
	return (resettable_iterate_frames_byte_indices(tile_kind, data, false));
}

void	sl_reset_iterate_frames_byte_indices(t_data *data)
{
	resettable_iterate_frames_byte_indices(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
