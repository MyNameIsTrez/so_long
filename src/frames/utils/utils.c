/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 12:29:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 11:58:05 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

uint32_t	sl_get_pixel_index(mlx_image_t *frame, t_data *data)
{
	const t_frame_pixels	*frame_pixels = &data->it.frame_pixels;
	const uint32_t			x = frame_pixels->x;
	const uint32_t			y = frame_pixels->y;
	const uint32_t			width = frame->width;
	const uint32_t			pixel_count = x + y * width;

	return (pixel_count * 4);
}

mlx_image_t	*sl_get_frame(t_tile_kind *tile_kind, uint32_t frame_index)
{
	return (tile_kind->frames[frame_index]);
}

mlx_instance_t	*sl_get_frame_instance(t_tile *tile, uint32_t frame_index)
{
	uint32_t			frame_instance_index;
	const mlx_image_t	*frame = sl_get_frame(tile->tile_kind, frame_index);

	frame_instance_index = tile->frame_instances_indices[frame_index];
	return (&frame->instances[frame_instance_index]);
}

////////////////////////////////////////////////////////////////////////////////
