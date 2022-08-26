/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_original_channel.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 17:57:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 17:59:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_u8	get_original_channel(t_data *data)
{
	t_it		*it;
	t_tile_kind	*tile_kind;
	t_u8		*original_channels;

	it = &data->it;
	tile_kind = it->tile_kind;
	original_channels = tile_kind->original_frames_pixels[it->frame_index];
	return (original_channels[it->frame_pixel_index + it->rgb_channel_index]);
}

////////////////////////////////////////////////////////////////////////////////
