/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tiles.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 13:22:41 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 11:14:08 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	sl_out_of_bounds(int32_t column, int32_t row, t_data *data)
{
	if (column < 0 || column >= (int32_t)data->char_grid.width)
		return (true);
	if (row < 0 || row >= (int32_t)data->char_grid.height)
		return (true);
	return (false);
}

t_status	sl_instantiate_tile_frames(t_tile *tile, t_data *data)
{
	int32_t				frame_instance_index;

	while (sl_iterate_frame_count(tile->tile_kind->frame_count, data) != FINISHED)
	{
		frame_instance_index = mlx_image_to_window(data->mlx,
				sl_get_frame(tile->tile_kind, data->t.frame_index),
				(int32_t)(data->texture.pixels_per_tile * data->t.column_index),
				(int32_t)(data->texture.pixels_per_tile * data->t.row_index));
		if (frame_instance_index < 0)
		{
			// TODO: Delete previous images in SL_ERROR_MLX42 cases?
			return (sl_set_error(SL_ERROR_MLX42));
		}
		tile->frame_instances_indices[data->t.frame_index] = (uint32_t)frame_instance_index;
		if (data->t.frame_index != 0)
			sl_get_frame_instance(tile, data->t.frame_index)->enabled = false;
	}
	return (OK);
}

void	sl_shift_tile_pos(t_tile *tile, int32_t columns, int32_t rows,
			t_data *data)
{
	const int32_t	pixels_per_tile = (int32_t)data->texture.pixels_per_tile;
	mlx_instance_t	*instance;

	tile->column_index = (uint32_t)((int32_t)tile->column_index + columns);
	tile->row_index = (uint32_t)((int32_t)tile->row_index + rows);
	while (sl_iterate_frame_count(tile->tile_kind->frame_count, data) != FINISHED)
	{
		instance = sl_get_frame_instance(tile, data->t.frame_index);
		instance->x += columns * pixels_per_tile;
		instance->y += rows * pixels_per_tile;
	}
}

t_status	sl_fill_tile_data(t_tile *tile, t_tile_kind *tile_kind,
				t_data *data)
{
	tile->tile_kind = tile_kind;
	tile->frame_index = 0;
	tile->frame_instances_indices = malloc(sizeof(uint32_t) * tile_kind->frame_count);
	if (tile->frame_instances_indices == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	tile->column_index = data->t.column_index;
	tile->row_index = data->t.row_index;
	return (OK);
}

t_tile	*sl_get_tile(t_data *data)
{
	return (data->tile_grid.cells[data->t.row_index][data->t.column_index]);
}

////////////////////////////////////////////////////////////////////////////////
