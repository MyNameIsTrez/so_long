/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window_height.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:25:26 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 17:42:54 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	init_window_height(size_t pixels_per_tile, t_data *data)
{
	// TODO: Sanitize WINDOW_OFFSETS
	data->window.height = (size_t)((t_i32)data->char_grid.height * \
		(t_i32)pixels_per_tile + (WINDOW_TOP_OFFSET + WINDOW_BOTTOM_OFFSET) * (t_i32)data->texture.scale);
	if (data->window.height > data->monitor.height)
		data->window.height = data->monitor.height;
}

////////////////////////////////////////////////////////////////////////////////
