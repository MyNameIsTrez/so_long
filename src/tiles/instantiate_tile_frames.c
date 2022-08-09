/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile_frames.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:37:17 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 17:42:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_tile_frames(t_tile *tile, t_data *data)
{
	t_iterator	it;
	size_t		frame_count;
	size_t		frame_index;
	t_i32		frame_instance_index;
	size_t		frame_instance_uindex;

	frame_count = tile->tile_kind->frame_count;
	ft_init_it(&it);
	while (sl_iterate_frame_count(&it, frame_count, data) != FINISHED)
	{
		frame_index = data->it.frame_index;
		frame_instance_index = mlx_image_to_window(data->mlx,
				sl_get_frame(tile->tile_kind, frame_index),
				(t_i32)(data->texture.pixels_per_tile * data->it.column) + WINDOW_LEFT_OFFSET * (t_i32)data->texture.scale,
				(t_i32)(data->texture.pixels_per_tile * data->it.row) + WINDOW_TOP_OFFSET * (t_i32)data->texture.scale);
		if (frame_instance_index < 0)
			return (sl_set_error(SL_ERROR_MLX42));
		frame_instance_uindex = (size_t)frame_instance_index;
		ft_vector_push(&tile->frame_instances_indices, &frame_instance_uindex);
		mlx_set_instance_depth(sl_get_frame_instance(tile, frame_index),
			tile->tile_kind->depth);
		if (frame_index != tile->frame_index)
			sl_get_frame_instance(tile, frame_index)->enabled = false;
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
