/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_tile_kinds_colors.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 17:52:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:16:14 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_initialize_tile_kinds_colors(t_data *data)
{
	mlx_image_t	*frame;
	t_u8		*pixels;

	while (sl_iterate_tile_kinds(data) != FINISHED)
	{
		while (sl_iterate_frames(data->it.tile_kind, data) != FINISHED)
		{
			while (sl_iterate_frame_pixel_indices(data->it.frame, data) != FINISHED)
			{
				frame = data->it.frame;
				pixels = frame->pixels;
				if (sl_is_opaque(data))
				{
					while (sl_iterate_rgb_channel_indices(data) != FINISHED)
					{
						pixels[data->it.pixel_index + data->it.rgb_channel_index] = data->it.tile_kind->color.initial_color[data->it.rgb_channel_index] * pixels[data->it.pixel_index + data->it.rgb_channel_index] / 255;
					}
				}
			}
		}
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
