/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pixel_index.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 16:32:17 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 16:32:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

size_t	sl_get_pixel_index(mlx_image_t *frame, t_data *data)
{
	t_frame_pixels	*frame_pixels;
	size_t			x;
	size_t			y;
	size_t			width;
	size_t			pixel_count;

	frame_pixels = &data->it.frame_pixels;
	x = frame_pixels->x;
	y = frame_pixels->y;
	width = frame->width;
	pixel_count = x + y * width;
	return (pixel_count * 4);
}

////////////////////////////////////////////////////////////////////////////////
