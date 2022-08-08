/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile_kind_color.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 15:42:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 16:58:32 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	instantiate_tile_kind_color(t_tile_kind_color *color,
				t_tile_kind_data_color tk_data_color, t_data *data)
{
	t_iterator	it;
	size_t		index;

	ft_init_it(&it);
	while (sl_iterate_rgb_channel_indices(&it, data) != FINISHED)
	{
		index = data->it.rgb_channel_index;
		color->initial_color[index] = tk_data_color.initial_color[index];
		color->min_color[index] = \
			color->initial_color[index] - tk_data_color.min_color_offset[index];
		color->max_color[index] = \
			color->initial_color[index] + tk_data_color.max_color_offset[index];
		color->step[index] = tk_data_color.step[index];
		color->wait[index] = tk_data_color.wait[index];
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
