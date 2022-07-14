/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frames.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 11:44:54 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 12:59:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frames(t_tile_kind *tile_kind,
			t_data *data, bool reset)
{
	uint32_t			frame_count;
	mlx_image_t			**frames;

	if (reset)
	{
		data->it.frame = NULL;
		return (RESET);
	}
	frame_count = tile_kind->frame_count;
	frames = tile_kind->frames;
	while (sl_iterate_frame_count(frame_count, data) != FINISHED)
	{
		data->it.frame = frames[data->it.frame_index];
		return (LOOPED);
	}
	sl_reset_iterate_frames(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frames(t_tile_kind *tile_kind, t_data *data)
{
	return (resettable_iterate_frames(tile_kind, data, false));
}

void	sl_reset_iterate_frames(t_data *data)
{
	resettable_iterate_frames(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
