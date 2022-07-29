/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_frame_instance.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 12:29:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:21:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

mlx_instance_t	*sl_get_frame_instance(t_tile *tile, size_t frame_index)
{
	mlx_image_t	*frame;
	size_t		frame_instance_index;

	frame = sl_get_frame(tile->tile_kind, frame_index);
	frame_instance_index = tile->frame_instances_indices[frame_index];
	return (&frame->instances[frame_instance_index]);
}

////////////////////////////////////////////////////////////////////////////////
