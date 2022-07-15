/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_frames.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/15 17:40:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

// Predicts what the color will be after a step and use that to change the rgb_step correctly:
// So if R is 2 and step is -3, R should end up as 2 -> 1 -> 0 -> 1, so 1
// If R is 253 and step is 6, R should end up as 253 -> 254 -> 255 -> 254 -> 253 -> 252 -> 251, so 251
STATIC void	update_frames(t_data *data)
{
	t_tile_kind	*tile_kind;
	t_i32		*rgb_step;
	t_u8		*channel;
	t_i32		step;

	while (sl_iterate_tile_kinds(data) != FINISHED)
	{
		tile_kind = data->it.tile_kind;
		rgb_step = tile_kind->color.step;
		while (sl_iterate_frames_pixel_indices(tile_kind, data) != FINISHED)
		{
			while (sl_iterate_rgb_channel_indices(data) != FINISHED)
			{
				if (data->frame % data->it.tile_kind->color.wait[data->it.rgb_channel_index] == 0)
				{
					if (sl_is_color(data))
					{
						channel = &data->it.frame->pixels[data->it.pixel_index + data->it.rgb_channel_index];
						step = rgb_step[data->it.rgb_channel_index];
						if (*channel + step < 0)
						{
							step += *channel;
							*channel = (t_u8)-step;
							rgb_step[data->it.rgb_channel_index] *= -1;
						}
						else if (*channel + step > 255)
						{
							step -= 255 - *channel;
							*channel = (t_u8)(255 - step);
							rgb_step[data->it.rgb_channel_index] *= -1;
						}
						else
						{
							*channel += step;
						}
					}
				}
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
