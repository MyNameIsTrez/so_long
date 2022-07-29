/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   step_pixel.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 16:57:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 16:57:56 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_step_pixel(t_data *data)
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

////////////////////////////////////////////////////////////////////////////////
