/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_frames.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 12:12:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	update_frames(t_tile_kind *tile_kind, t_data *data)
{
	static t_color_step	color_step = {-1, -1, -1};
	uint32_t			pixel_index;
	uint32_t			pixels_data_index;

	while (sl_iterate_frames(tile_kind, data) != FINISHED)
	{
		while (sl_iterate_frame_pixels(data->it.frame, data) != FINISHED)
		{
			pixel_index = sl_get_pixel_index(data->it.frame, data);
			while (sl_iterate_channel_indices(data) != FINISHED)
			{
				pixels_data_index = pixel_index + data->it.channel_index;
				if (data->it.channel_index == 0 && data->frame % 1 == 0)
					if (data->it.frame->pixels[pixels_data_index + 3] > 0)
					{
						data->it.frame->pixels[pixels_data_index] += color_step.r;
						if (data->it.frame->pixels[pixels_data_index] == 0 || data->it.frame->pixels[pixels_data_index] == 255)
							color_step.r *= -1;
					}
				if (data->it.channel_index == 1 && data->frame % 2 == 0)
					if (data->it.frame->pixels[pixels_data_index + 2] > 0)
					{
						data->it.frame->pixels[pixels_data_index] += color_step.g;
						if (data->it.frame->pixels[pixels_data_index] == 0 || data->it.frame->pixels[pixels_data_index] == 255)
							color_step.g *= -1;
					}
				if (data->it.channel_index == 2 && data->frame % 3 == 0)
					if (data->it.frame->pixels[pixels_data_index + 1] > 0)
					{
						data->it.frame->pixels[pixels_data_index] += color_step.b;
						if (data->it.frame->pixels[pixels_data_index] == 0 || data->it.frame->pixels[pixels_data_index] == 255)
							color_step.b *= -1;
					}
			}
		}
	}
}

STATIC void	update_wall_frames(unsigned char tile_kind_character, t_data *data)
{
	t_tile_kind	*tile_kind;

	tile_kind = &data->tile_kinds[tile_kind_character];
	update_frames(tile_kind, data);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_update_frames(t_data *data)
{
	update_wall_frames(WALL_CHARACTER, data);
}

////////////////////////////////////////////////////////////////////////////////
