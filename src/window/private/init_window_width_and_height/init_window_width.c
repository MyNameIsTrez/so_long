/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window_width.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:25:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 18:27:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	init_window_width(size_t pixels_per_tile, t_data *data)
{
	size_t	grid_width;
	t_i32	window_offset;

	grid_width = data->char_grid.width * pixels_per_tile;
	window_offset = (WINDOW_LEFT_OFFSET + WINDOW_RIGHT_OFFSET) * \
		(t_i32)data->texture.scale;
	// TODO: Sanitize WINDOW_OFFSETS
	data->window.width = (size_t)((t_i32)grid_width + window_offset);
	if (data->window.width > data->monitor.width)
		data->window.width = data->monitor.width;
}

////////////////////////////////////////////////////////////////////////////////
