/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_x.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/29 11:02:32 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/29 11:02:32 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_i32	get_x(t_data *data)
{
	size_t	column;
	t_i32	column_pixels;
	t_i32	window_left_pixel_offset;

	column = sl_get_column(data->it.char_grid_index, data);
	column_pixels = (t_i32)(data->texture.pixels_per_tile * column);
	window_left_pixel_offset = WINDOW_LEFT_OFFSET * (t_i32)data->texture.scale;
	return (column_pixels + window_left_pixel_offset);
}

////////////////////////////////////////////////////////////////////////////////
