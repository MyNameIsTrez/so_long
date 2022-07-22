/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_pixel_indices.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 15:09:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 17:37:56 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frame_pixel_indices(
								mlx_image_t *frame, t_data *data, bool reset)
{
	if (reset)
	{
		sl_reset_iterate_frame_pixels(data);
		return (RESET);
	}
	while (sl_iterate_frame_pixels(frame, data) != FINISHED)
	{
		data->it.pixel_index = sl_get_pixel_index(frame, data);
		return (LOOPED);
	}
	sl_reset_iterate_frame_pixel_indices(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_pixel_indices(mlx_image_t *frame,
						t_data *data)
{
	return (resettable_iterate_frame_pixel_indices(frame, data, false));
}

void	sl_reset_iterate_frame_pixel_indices(t_data *data)
{
	resettable_iterate_frame_pixel_indices(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
