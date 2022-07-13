/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_frames.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/13 13:01:33 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	update_wall_frames(mlx_image_t *frame, t_data *data)
{
	uint32_t	pixel_index;
	uint32_t	pixels_data_index;

	while (sl_iterate_frame_pixels(frame, data) != FINISHED)
	{
		pixel_index = sl_get_pixel_index(frame, data);
		while (sl_iterate_channel_indices(data) != FINISHED)
		{
			pixels_data_index = pixel_index + data->t.channel_index;
			if (data->t.channel_index == 0)
				if (frame->pixels[pixels_data_index + 3] > 0)
					frame->pixels[pixels_data_index]++;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////

void	sl_update_frames(t_data *data)
{
	update_wall_frames(data->tile_kinds[WALL_CHARACTER].frames[0], data);
}

////////////////////////////////////////////////////////////////////////////////
