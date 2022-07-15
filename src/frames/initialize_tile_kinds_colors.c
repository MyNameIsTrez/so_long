/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_tile_kinds_colors.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 17:52:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/15 16:49:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_initialize_tile_kinds_colors(t_data *data)
{
	t_rgba		initial_color;
	mlx_image_t	*frame;
	t_u8		*pixels;

	initial_color.a = 255;
	sl_reset_iterate_tile_kinds(data);
	while (sl_iterate_tile_kinds(data) != FINISHED)
	{
		while (sl_iterate_frames(data->it.tile_kind, data) != FINISHED)
		{
			while (sl_iterate_frame_pixel_indices(data->it.frame, data) != FINISHED)
			{
				frame = data->it.frame;
				pixels = frame->pixels;
				if (sl_is_color(data))
				{
					initial_color.r = data->it.tile_kind->color.initial_color.r;
					initial_color.g = data->it.tile_kind->color.initial_color.g;
					initial_color.b = data->it.tile_kind->color.initial_color.b;
					ft_memcpy(&pixels[data->it.pixel_index], &initial_color, 4);
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
