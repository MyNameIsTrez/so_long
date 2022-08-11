/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_tile_pos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 20:13:01 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 18:44:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_set_tile_pos(t_tile *tile, size_t index, t_data *data)
{
	t_iterator		it;
	size_t			frame_count;
	size_t			pixels_per_tile;
	mlx_instance_t	*instance;

	tile->index = index;
	frame_count = tile->tile_kind->frame_count;
	pixels_per_tile = data->texture.pixels_per_tile;
	ft_init_it(&it);
	while (sl_iterate_frame_count(&it, frame_count, data) != FINISHED)
	{
		instance = sl_get_frame_instance(tile, data->it.frame_index);
		instance->x = (t_i32)sl_get_column(index, data) * (t_i32)pixels_per_tile + WINDOW_LEFT_OFFSET * (t_i32)data->texture.scale;
		instance->y = (t_i32)sl_get_row(index, data) * (t_i32)pixels_per_tile + WINDOW_TOP_OFFSET * (t_i32)data->texture.scale;
	}
}

////////////////////////////////////////////////////////////////////////////////
