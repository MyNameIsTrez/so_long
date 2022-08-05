/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_tile_pos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 20:13:01 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 20:19:10 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_set_tile_pos(t_tile *tile, size_t column, size_t row, t_data *data)
{
	size_t			pixels_per_tile;
	size_t			frame_count;
	mlx_instance_t	*instance;

	tile->column_index = column;
	tile->row_index = row;
	frame_count = tile->tile_kind->frame_count;
	pixels_per_tile = data->texture.pixels_per_tile;
	while (sl_iterate_frame_count(frame_count, data) != FINISHED)
	{
		instance = sl_get_frame_instance(tile, data->it.frame_index);
		instance->x = (t_i32)column * (t_i32)pixels_per_tile;
		instance->y = (t_i32)row * (t_i32)pixels_per_tile;
	}
}

////////////////////////////////////////////////////////////////////////////////
