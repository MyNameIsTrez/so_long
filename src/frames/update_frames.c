/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_frames.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/15 15:32:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	update_frames(t_data *data)
{
	t_rgb_step	*color_step;

	while (sl_iterate_tile_kinds(data) != FINISHED)
	{
		while (sl_iterate_frames_byte_indices(data->it.tile_kind, data) != FINISHED)
		{
			color_step = &data->it.tile_kind->color.step;
			if (data->it.channel_index == 0 && data->frame % 1 == 0)
				// TODO: Use sl_is_opaque() somehow here
				if (data->it.frame->pixels[data->it.frame_byte_index + 3] > 0)
				{
					data->it.frame->pixels[data->it.frame_byte_index] += color_step->r;
					if (data->it.frame->pixels[data->it.frame_byte_index] == 0 || data->it.frame->pixels[data->it.frame_byte_index] == 255)
						color_step->r *= -1;
				}
			if (data->it.channel_index == 1 && data->frame % 2 == 0)
				if (data->it.frame->pixels[data->it.frame_byte_index + 2] > 0)
				{
					data->it.frame->pixels[data->it.frame_byte_index] += color_step->g;
					if (data->it.frame->pixels[data->it.frame_byte_index] == 0 || data->it.frame->pixels[data->it.frame_byte_index] == 255)
						color_step->g *= -1;
				}
			if (data->it.channel_index == 2 && data->frame % 3 == 0)
				if (data->it.frame->pixels[data->it.frame_byte_index + 1] > 0)
				{
					data->it.frame->pixels[data->it.frame_byte_index] += color_step->b;
					if (data->it.frame->pixels[data->it.frame_byte_index] == 0 || data->it.frame->pixels[data->it.frame_byte_index] == 255)
						color_step->b *= -1;
				}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////

void	sl_update_frames(t_data *data)
{
	update_frames(data);
}

////////////////////////////////////////////////////////////////////////////////
