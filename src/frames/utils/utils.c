/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 12:29:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 15:35:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_u32	sl_get_pixel_index(mlx_image_t *frame, t_data *data)
{
	const t_frame_pixels	*frame_pixels = &data->it.frame_pixels;
	const t_u32			x = frame_pixels->x;
	const t_u32			y = frame_pixels->y;
	const t_u32			width = frame->width;
	const t_u32			pixel_count = x + y * width;

	return (pixel_count * 4);
}

mlx_image_t	*sl_get_frame(t_tile_kind *tile_kind, t_u32 frame_index)
{
	return (tile_kind->frames[frame_index]);
}

mlx_instance_t	*sl_get_frame_instance(t_tile *tile, t_u32 frame_index)
{
	t_u32			frame_instance_index;
	const mlx_image_t	*frame = sl_get_frame(tile->tile_kind, frame_index);

	frame_instance_index = tile->frame_instances_indices[frame_index];
	return (&frame->instances[frame_instance_index]);
}

////////////////////////////////////////////////////////////////////////////////
