/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_frames.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/13 11:50:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC uint32_t	get_pixel_index(mlx_image_t *frame, t_data *data)
{
	const t_frame_pixels	*frame_pixels = &data->t.frame_pixels;
	const uint32_t			x = frame_pixels->x;
	const uint32_t			y = frame_pixels->y;
	const uint32_t			width = frame->width;

	return (x + y * width);
}

STATIC void	update_wall_frames(mlx_image_t *frame, t_data *data)
{
	uint32_t	pixel_index;
	uint32_t	pixels_data_index;

	while (sl_iterate_frame_pixels(frame, data) != FINISHED)
	{
		pixel_index = get_pixel_index(frame, data);
		while (sl_iterate_channel_indices(data) != FINISHED)
		{
			pixels_data_index = pixel_index * 4 + data->t.channel_index;
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
