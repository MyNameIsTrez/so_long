/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window_height.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:25:26 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 18:25:13 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	init_window_height(size_t pixels_per_tile, t_data *data)
{
	size_t	grid_height;
	t_i32	window_offset;

	grid_height = data->char_grid.height * pixels_per_tile;
	window_offset = (WINDOW_TOP_OFFSET + WINDOW_BOTTOM_OFFSET) * \
		(t_i32)data->texture.scale;
	// TODO: Sanitize WINDOW_OFFSETS
	data->window.height = (size_t)((t_i32)grid_height + window_offset);
	if (data->window.height > data->monitor.height)
		data->window.height = data->monitor.height;
}

////////////////////////////////////////////////////////////////////////////////
