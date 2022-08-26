/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_max_channel.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 17:56:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 18:11:51 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_u8	get_max_channel(size_t rgb_channel_index, t_u8 original_channel,
			t_data *data)
{
	t_tile_kind	*tile_kind;
	t_u8		max_channel;

	tile_kind = data->it.tile_kind;
	max_channel = tile_kind->color.max_color[rgb_channel_index];
	return (max_channel * original_channel / 255);
}

////////////////////////////////////////////////////////////////////////////////
