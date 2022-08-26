/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_channels.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 19:17:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 19:25:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	initialize_channels(t_u8 *pixels, t_data *data)
{
	t_it		*it;
	size_t		frame_pixel_index;
	t_iterator	rgb_channel_indices_it;
	size_t		rgb_channel_index;
	t_u8		initial_channel;

	it = &data->it;
	frame_pixel_index = it->frame_pixel_index;
	ft_init_it(&rgb_channel_indices_it);
	while (sl_iterate_rgb_channel_indices(&rgb_channel_indices_it,
			data) != FINISHED)
	{
		rgb_channel_index = it->rgb_channel_index;
		initial_channel = it->tile_kind->color.initial_color[rgb_channel_index];
		pixels[frame_pixel_index + rgb_channel_index] = initial_channel * \
			pixels[frame_pixel_index + rgb_channel_index] / 255;
	}
}

////////////////////////////////////////////////////////////////////////////////
