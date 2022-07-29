/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_frame_colors.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:00:37 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

// Predicts what the color will be after a step and use that to change the rgb_step correctly:
// So if R is 2 and step is -3, R should end up as 2 -> 1 -> 0 -> 1, so 1
// If R is 253 and step is 6, R should end up as 253 -> 254 -> 255 -> 254 -> 253 -> 252 -> 251, so 251
void	sl_update_frame_colors(t_data *data)
{
	while (sl_iterate_tile_kinds(data) != FINISHED)
	{
		while (sl_iterate_frames_pixel_indices(data->it.tile_kind, data) != FINISHED)
		{
			while (sl_iterate_rgb_channel_indices(data) != FINISHED)
			{
				if (sl_should_step(data))
				{
					if (sl_is_opaque(data))
					{
						sl_step_pixel(data);
					}
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
