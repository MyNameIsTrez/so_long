/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window_width.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:25:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 17:42:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	init_window_width(size_t pixels_per_tile, t_data *data)
{
	// TODO: Sanitize WINDOW_OFFSETS
	data->window.width = (size_t)((t_i32)data->char_grid.width * \
		(t_i32)pixels_per_tile + (WINDOW_LEFT_OFFSET + WINDOW_RIGHT_OFFSET) * (t_i32)data->texture.scale);
	if (data->window.width > data->monitor.width)
		data->window.width = data->monitor.width;
}

////////////////////////////////////////////////////////////////////////////////
