/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_max_color_offset.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:55:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 17:00:22 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_max_color_offset(
				t_tile_kind_data_color tile_kind_data_color, t_data *data)
{
	t_iterator	it;
	size_t		channel;

	ft_init_it(&it);
	while (sl_iterate_rgb_channel_indices(&it, data) != FINISHED)
	{
		channel = data->it.rgb_channel_index;
		if (tile_kind_data_color.initial_color[channel] + \
			tile_kind_data_color.max_color_offset[channel] > 255)
			return (sl_set_error(SL_ERROR_TOO_HIGH_MAX_COLOR));
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
