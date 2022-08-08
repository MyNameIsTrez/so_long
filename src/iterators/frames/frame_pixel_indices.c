/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_pixel_indices.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 15:09:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 16:39:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_pixel_indices(t_it_frame_pixels *it,
						mlx_image_t *frame, t_data *data)
{
	while (sl_iterate_frame_pixels(it, frame, data) != FINISHED)
	{
		data->it.pixel_index = sl_get_pixel_index(frame, data);
		return (LOOPED);
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
