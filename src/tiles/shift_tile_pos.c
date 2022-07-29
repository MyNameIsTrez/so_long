/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shift_tile_pos.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:37:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:37:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_shift_tile_pos(t_tile *tile, t_i32 columns, t_i32 rows, t_data *data)
{
	size_t			pixels_per_tile;
	size_t			frame_count;
	mlx_instance_t	*instance;

	pixels_per_tile = data->texture.pixels_per_tile;
	tile->column_index = (size_t)((t_i32)tile->column_index + columns);
	tile->row_index = (size_t)((t_i32)tile->row_index + rows);
	frame_count = tile->tile_kind->frame_count;
	while (sl_iterate_frame_count(frame_count, data) != FINISHED)
	{
		instance = sl_get_frame_instance(tile, data->it.frame_index);
		instance->x += columns * (t_i32)pixels_per_tile;
		instance->y += rows * (t_i32)pixels_per_tile;
	}
}

////////////////////////////////////////////////////////////////////////////////
