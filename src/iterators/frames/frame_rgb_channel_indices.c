/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_rgb_channel_indices.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 12:12:41 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frame_rgb_channel_indices(
								mlx_image_t *frame, t_data *data, bool reset)
{
	if (reset)
	{
		sl_reset_iterate_frame_pixels(data);
		sl_reset_iterate_rgb_channel_indices(data);
		return (RESET);
	}
	while (true)
	{
		while (true)
		{
			if (sl_iterate_rgb_channel_indices(data) != LOOPED)
				break ;
			return (LOOPED);
		}
		sl_reset_iterate_rgb_channel_indices(data);
		if (data->it.frame_pixels.x == 0 && data->it.frame_pixels.y == 0)
			sl_iterate_frame_pixels(frame, data);
		if (sl_iterate_frame_pixels(frame, data) != LOOPED)
			break ;
	}
	sl_reset_iterate_frame_rgb_channel_indices(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_rgb_channel_indices(mlx_image_t *frame,
						t_data *data)
{
	return (resettable_iterate_frame_rgb_channel_indices(frame, data, false));
}

void	sl_reset_iterate_frame_rgb_channel_indices(t_data *data)
{
	resettable_iterate_frame_rgb_channel_indices(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
