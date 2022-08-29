/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_min_color.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:56:15 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 11:31:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_min_color(
				t_tile_kind_color tile_kind_data_color, t_data *data)
{
	t_iterator	it;
	size_t		channel;

	ft_init_it(&it);
	while (sl_iterate_rgb_channel_indices(&it, data) != FINISHED)
	{
		channel = data->it.rgb_channel_index;
		if (tile_kind_data_color.min_color[channel] > \
			tile_kind_data_color.initial_color[channel])
			return (sl_set_error(SL_ERROR_TOO_HIGH_MIN_COLOR));
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
