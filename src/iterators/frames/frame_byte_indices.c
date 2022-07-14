/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_byte_indices.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 12:27:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 12:34:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frame_byte_indices(
			mlx_image_t *frame, t_data *data, bool reset)
{
	uint32_t	pixel_index;

	if (reset)
	{
		sl_reset_iterate_frame_channels(data);
		data->it.frame_byte_index = 0;
		return (RESET);
	}
	while (sl_iterate_frame_channels(frame, data) != FINISHED)
	{
		pixel_index = sl_get_pixel_index(frame, data);
		data->it.frame_byte_index = pixel_index + data->it.channel_index;
		return (LOOPED);
	}
	sl_reset_iterate_frame_byte_indices(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_byte_indices(mlx_image_t *frame,
			t_data *data)
{
	return (resettable_iterate_frame_byte_indices(frame, data, false));
}

void	sl_reset_iterate_frame_byte_indices(t_data *data)
{
	resettable_iterate_frame_byte_indices(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
