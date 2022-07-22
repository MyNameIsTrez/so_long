/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tiles.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 13:22:41 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 21:49:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	sl_out_of_bounds(t_i32 column, t_i32 row, t_data *data)
{
	if (column < 0 || column >= data->char_grid.width)
		return (true);
	if (row < 0 || row >= data->char_grid.height)
		return (true);
	return (false);
}

t_status	sl_instantiate_tile_frames(t_tile *tile, t_data *data)
{
	t_i32	frame_count;
	t_i32	frame_index;
	t_i32	frame_instance_index;

	frame_count = tile->tile_kind->frame_count;
	while (sl_iterate_frame_count(frame_count, data) != FINISHED)
	{
		frame_index = data->it.frame_index;
		frame_instance_index = mlx_image_to_window(data->mlx,
				sl_get_frame(tile->tile_kind, frame_index),
				data->texture.pixels_per_tile * data->it.column_index,
				data->texture.pixels_per_tile * data->it.row_index);
		if (frame_instance_index < 0)
		{
			// TODO: Delete previous images in SL_ERROR_MLX42 cases?
			return (sl_set_error(SL_ERROR_MLX42));
		}
		tile->frame_instances_indices[frame_index] = frame_instance_index;
		if (frame_index != 0)
			sl_get_frame_instance(tile, frame_index)->enabled = false;
	}
	return (OK);
}

void	sl_shift_tile_pos(t_tile *tile, t_i32 columns, t_i32 rows, t_data *data)
{
	t_i32			pixels_per_tile;
	t_i32			frame_count;
	mlx_instance_t	*instance;

	pixels_per_tile = data->texture.pixels_per_tile;
	tile->column_index = tile->column_index + columns;
	tile->row_index = tile->row_index + rows;
	frame_count = tile->tile_kind->frame_count;
	while (sl_iterate_frame_count(frame_count, data) != FINISHED)
	{
		instance = sl_get_frame_instance(tile, data->it.frame_index);
		instance->x += columns * pixels_per_tile;
		instance->y += rows * pixels_per_tile;
	}
}

t_status	sl_fill_tile_data(t_tile *tile, t_tile_kind *tile_kind,
				t_data *data)
{
	t_i32	frame_count;

	tile->tile_kind = tile_kind;
	tile->frame_index = 0;
	frame_count = tile_kind->frame_count;
	tile->frame_instances_indices = ft_malloc((size_t)frame_count, sizeof(t_i32));
	if (tile->frame_instances_indices == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	tile->column_index = data->it.column_index;
	tile->row_index = data->it.row_index;
	return (OK);
}

t_tile	*sl_get_tile(t_data *data)
{
	return (&data->tile_grid.cells[data->it.row_index][data->it.column_index]);
}

////////////////////////////////////////////////////////////////////////////////
