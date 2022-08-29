/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile_frame.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/29 10:55:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/29 10:55:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_tile_frame(t_tile *tile, size_t frame_index,
				t_data *data)
{
	mlx_image_t	*frame;
	int32_t		x;
	int32_t		y;
	t_i32		frame_instance_index;
	size_t		frame_instance_uindex;

	frame = sl_get_frame(tile->tile_kind, frame_index);
	x = sl_get_instance_x(data->it.char_grid_index, data);
	y = sl_get_instance_y(data->it.char_grid_index, data);
	frame_instance_index = mlx_image_to_window(data->mlx, frame, x, y);
	if (frame_instance_index < 0)
		return (sl_set_error(SL_ERROR_MLX42));
	frame_instance_uindex = (size_t)frame_instance_index;
	if (ft_vector_push(&tile->frame_instances_indices,
			&frame_instance_uindex) != OK)
		return (ERROR);
	mlx_set_instance_depth(sl_get_frame_instance(tile, frame_index),
		tile->tile_kind->depth);
	if (frame_index != tile->frame_index)
		sl_get_frame_instance(tile, frame_index)->enabled = false;
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
