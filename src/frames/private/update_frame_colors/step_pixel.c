/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   step_pixel.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 16:57:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 18:08:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	step_pixel(mlx_image_t *frame, t_data *data)
{
	t_u8		*pixels;
	size_t		rgb_channel_index;
	t_u8		*channel;
	t_i32		step;
	t_tile_kind	*tile_kind;
	t_i32		*rgb_step;
	t_u8		*original_channels;
	t_u8		original_channel;
	t_u8		min_channel;
	t_u8		max_channel;

	pixels = frame->pixels;
	rgb_channel_index = data->it.rgb_channel_index;
	channel = &pixels[data->it.frame_pixel_index + rgb_channel_index];
	tile_kind = data->it.tile_kind;
	rgb_step = tile_kind->color.step;
	step = rgb_step[rgb_channel_index];
	original_channels = tile_kind->original_frames_pixels[data->it.frame_index];
	original_channel = original_channels[data->it.frame_pixel_index + data->it.rgb_channel_index];
	min_channel = tile_kind->color.min_color[rgb_channel_index] * original_channel / 255;
	max_channel = tile_kind->color.max_color[rgb_channel_index] * original_channel / 255;
	if (*channel + step < min_channel)
	{
		step += *channel - min_channel;
		if (min_channel - step <= max_channel)
			*channel = (t_u8)(min_channel - step);
		rgb_step[rgb_channel_index] *= -1;
	}
	else if (*channel + step > max_channel)
	{
		step -= max_channel - *channel;
		if (max_channel - step >= min_channel)
			*channel = (t_u8)(max_channel - step);
		rgb_step[rgb_channel_index] *= -1;
	}
	else
		*channel += step;
}

////////////////////////////////////////////////////////////////////////////////
