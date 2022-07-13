/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 12:29:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/13 13:00:54 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

uint32_t	sl_get_pixel_index(mlx_image_t *frame, t_data *data)
{
	const t_frame_pixels	*frame_pixels = &data->t.frame_pixels;
	const uint32_t			x = frame_pixels->x;
	const uint32_t			y = frame_pixels->y;
	const uint32_t			width = frame->width;
	const uint32_t			pixel_count = x + y * width;

	return (pixel_count * 4);
}

////////////////////////////////////////////////////////////////////////////////
