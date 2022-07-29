/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_frame_colors.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 16:28:55 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	step_pixel(t_data *data)
{
	t_u8		*pixels;
	size_t		rgb_channel_index;
	t_u8		*channel;
	t_i32		step;
	t_tile_kind	*tile_kind;
	t_i32		*rgb_step;
	t_i32		*min_color;
	t_i32		*max_color;

	pixels = data->it.frame->pixels;
	rgb_channel_index = data->it.rgb_channel_index;
	channel = &pixels[data->it.pixel_index + rgb_channel_index];
	tile_kind = data->it.tile_kind;
	rgb_step = tile_kind->color.step;
	step = rgb_step[rgb_channel_index];
	min_color = tile_kind->color.min_color;
	max_color = tile_kind->color.max_color;
	if (*channel + step < min_color[rgb_channel_index])
	{
		step += *channel - min_color[rgb_channel_index];
		*channel = (t_u8)(min_color[rgb_channel_index] - step);
		rgb_step[rgb_channel_index] *= -1;
	}
	else if (*channel + step > max_color[rgb_channel_index])
	{
		step -= max_color[rgb_channel_index] - *channel;
		*channel = (t_u8)(max_color[rgb_channel_index] - step);
		rgb_step[rgb_channel_index] *= -1;
	}
	else
		*channel += step;
}

STATIC bool	should_step(t_data *data)
{
	t_i32	*wait;
	size_t	rgb_channel_index;

	wait = data->it.tile_kind->color.wait;
	rgb_channel_index = data->it.rgb_channel_index;
	return (data->frame % wait[rgb_channel_index] == 0);
}

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
				if (should_step(data))
				{
					if (sl_is_opaque(data))
					{
						step_pixel(data);
					}
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
