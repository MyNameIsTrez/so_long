/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_instance_y.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/29 11:02:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/29 11:02:42 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_i32	sl_get_instance_y(size_t index, t_data *data)
{
	size_t	row;
	t_i32	row_pixels;
	t_i32	window_left_pixel_offset;

	row = sl_get_row(index, data);
	row_pixels = (t_i32)(data->texture.pixels_per_tile * row);
	window_left_pixel_offset = WINDOW_TOP_OFFSET * (t_i32)data->texture.scale;
	return (row_pixels + window_left_pixel_offset);
}

////////////////////////////////////////////////////////////////////////////////
