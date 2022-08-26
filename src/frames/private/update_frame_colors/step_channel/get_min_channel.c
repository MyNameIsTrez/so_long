/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_min_channel.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 17:56:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 18:11:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_u8	get_min_channel(size_t rgb_channel_index, t_u8 original_channel,
			t_data *data)
{
	t_tile_kind	*tile_kind;
	t_u8		min_channel;

	tile_kind = data->it.tile_kind;
	min_channel = tile_kind->color.min_color[rgb_channel_index];
	return (min_channel * original_channel / 255);
}

////////////////////////////////////////////////////////////////////////////////
