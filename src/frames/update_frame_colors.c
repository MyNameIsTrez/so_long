/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_frame_colors.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 15:59:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/update_frame_colors/sl_private_update_frame_colors.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/sl_private_frames.h"

////////////////////////////////////////////////////////////////////////////////

// Predicts what the color will be after a step and use that to change the rgb_step correctly:
// So if R is 2 and step is -3, R should end up as 2 -> 1 -> 0 -> 1, so 1
// If R is 253 and step is 6, R should end up as 253 -> 254 -> 255 -> 254 -> 253 -> 252 -> 251, so 251
void	sl_update_frame_colors(t_data *data)
{
	t_iterator					tile_kinds_it;
	t_it_frames_pixel_indices	frames_pixels_indices_it;
	t_iterator					rgb_channel_indices_it;

	ft_init_it(&tile_kinds_it);
	sl_init_it_frames_pixel_indices(&frames_pixels_indices_it);
	ft_init_it(&rgb_channel_indices_it);
	while (sl_iterate_tile_kinds(&tile_kinds_it, data) != FINISHED)
	{
		while (sl_iterate_frames_pixel_indices(&frames_pixels_indices_it,
				data->it.tile_kind, data) != FINISHED)
		{
			while (sl_iterate_rgb_channel_indices(&rgb_channel_indices_it,
					data) != FINISHED)
			{
				if (should_step(data))
				{
					if (is_visible(data))
					{
						step_pixel(data);
					}
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
