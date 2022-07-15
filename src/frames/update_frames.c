/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_frames.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/15 16:22:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	update_frames(t_data *data)
{
	t_tile_kind	*tile_kind;
	t_rgb_step	*color_step;

	while (sl_iterate_tile_kinds(data) != FINISHED)
	{
		tile_kind = data->it.tile_kind;
		while (sl_iterate_frames_pixel_indices(tile_kind, data) != FINISHED)
		{
			color_step = &tile_kind->color.step;
			if (data->frame % 1 == 0)
				// TODO: Use sl_is_opaque() here once the new iterator TODO above is used
				if (data->it.frame->pixels[data->it.pixel_index + 0 + 3] > 0)
				{
					data->it.frame->pixels[data->it.pixel_index + 0] += color_step->r;
					if (data->it.frame->pixels[data->it.pixel_index + 0] == 0 || data->it.frame->pixels[data->it.pixel_index + 0] == 255)
						color_step->r *= -1;
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
