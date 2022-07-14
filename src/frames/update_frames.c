/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_frames.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 11:36:43 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	update_wall_frames(unsigned char tile_kind_character, t_data *data)
{
	static t_color_step	color_step = {-1, -1, -1};
	uint32_t			pixel_index;
	uint32_t			pixels_data_index;
	t_tile_kind			*tile_kind;
	mlx_image_t			*frame;

	tile_kind = &data->tile_kinds[tile_kind_character];
	frame = tile_kind->frames[0];
	while (sl_iterate_frame_pixels(frame, data) != FINISHED)
	{
		pixel_index = sl_get_pixel_index(frame, data);
		while (sl_iterate_channel_indices(data) != FINISHED)
		{
			pixels_data_index = pixel_index + data->t.channel_index;
			if (data->t.channel_index == 0 && data->frame % 1 == 0)
				if (frame->pixels[pixels_data_index + 3] > 0)
				{
					frame->pixels[pixels_data_index] += color_step.r;
					if (frame->pixels[pixels_data_index] == 0 || frame->pixels[pixels_data_index] == 255)
						color_step.r *= -1;
				}
			if (data->t.channel_index == 1 && data->frame % 2 == 0)
				if (frame->pixels[pixels_data_index + 2] > 0)
				{
					frame->pixels[pixels_data_index] += color_step.g;
					if (frame->pixels[pixels_data_index] == 0 || frame->pixels[pixels_data_index] == 255)
						color_step.g *= -1;
				}
			if (data->t.channel_index == 2 && data->frame % 3 == 0)
				if (frame->pixels[pixels_data_index + 1] > 0)
				{
					frame->pixels[pixels_data_index] += color_step.b;
					if (frame->pixels[pixels_data_index] == 0 || frame->pixels[pixels_data_index] == 255)
						color_step.b *= -1;
				}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////

void	sl_update_frames(t_data *data)
{
	update_wall_frames(WALL_CHARACTER, data);
}

////////////////////////////////////////////////////////////////////////////////
