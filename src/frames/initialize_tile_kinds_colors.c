/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_tile_kinds_colors.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 17:52:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 15:59:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/sl_private_frames.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_initialize_tile_kinds_colors(t_data *data)
{
	t_iterator			tile_kind_it;
	t_iterator			frames_it;
	t_it_frame_pixels	frame_pixel_indices_it;
	t_iterator			rgb_channel_indices_it;
	mlx_image_t			*frame;
	t_u8				*pixels;

	ft_init_it(&tile_kind_it);
	ft_init_it(&frames_it);
	sl_init_it_frame_pixels(&frame_pixel_indices_it);
	ft_init_it(&rgb_channel_indices_it);
	while (sl_iterate_tile_kinds(&tile_kind_it, data) != FINISHED)
	{
		while (sl_iterate_frames(&frames_it, data->it.tile_kind, data) != FINISHED)
		{
			while (sl_iterate_frame_pixel_indices(&frame_pixel_indices_it, data->it.frame, data) != FINISHED)
			{
				frame = data->it.frame;
				pixels = frame->pixels;
				if (is_visible(data))
				{
					while (sl_iterate_rgb_channel_indices(&rgb_channel_indices_it, data) != FINISHED)
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
