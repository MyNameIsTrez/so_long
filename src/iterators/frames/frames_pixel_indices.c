/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frames_pixel_indices.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 16:01:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frames_pixel_indices(
								t_tile_kind *tile_kind, t_data *data,
								bool reset)
{
	if (reset)
	{
		sl_reset_iterate_frames(data);
		sl_reset_iterate_frame_pixel_indices(data);
		return (RESET);
	}
	while (true)
	{
		if (data->it.frame == NULL)
			sl_iterate_frames(tile_kind, data);
		while (true)
		{
			if (sl_iterate_frame_pixel_indices(data->it.frame, data) != LOOPED)
				break ;
			return (LOOPED);
		}
		sl_reset_iterate_frame_pixel_indices(data);
		if (sl_iterate_frames(tile_kind, data) != LOOPED)
			break ;
	}
	sl_reset_iterate_frames_pixel_indices(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frames_pixel_indices(t_tile_kind *tile_kind,
						t_data *data)
{
	return (resettable_iterate_frames_pixel_indices(tile_kind, data, false));
}

void	sl_reset_iterate_frames_pixel_indices(t_data *data)
{
	resettable_iterate_frames_pixel_indices(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
