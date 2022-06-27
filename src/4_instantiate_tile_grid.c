/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_instantiate_tile_grid.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 18:02:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/27 17:38:23 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC mlx_image_t	*get_image(t_tile_type *tile_type, uint32_t frame_index)
{
	return (tile_type->frames[frame_index]);
}

STATIC t_success	malloc_tile(t_tile_type *tile_type, t_tile **tile)
{
	*tile = malloc(sizeof(t_tile));
	if (*tile == NULL)
		return (ft_set_error(ERROR_MALLOC));
	(*tile)->tile_type = tile_type;
	(*tile)->frame_index = 0;
	(*tile)->frame_instances_indices = malloc(sizeof(int32_t) * tile_type->frame_count);
	if ((*tile)->frame_instances_indices == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (SUCCESS);
}

STATIC t_tile_type	*get_tile_type(uint32_t column_index, uint32_t row_index, t_data *data)
{
	char const	grid_character = data->char_grid.cells[row_index][column_index];

	return (&data->tile_types[(unsigned char)grid_character]);
}

STATIC t_success	instantiate_tile(uint32_t column_index, uint32_t row_index,
			t_data *data)
{
	t_tile_type*const	tile_type = get_tile_type(column_index, row_index, data);
	t_tile				*tile;
	uint32_t			frame_index;
	uint32_t const		frame_count = tile_type->frame_count;
	int32_t				frame_instance_index;

	if (malloc_tile(tile_type, &data->tile_grid.cells[row_index][column_index]) != SUCCESS)
		return (ft_get_error());
	tile = data->tile_grid.cells[row_index][column_index];
	frame_index = 0;
	while (frame_index < frame_count)
	{
		frame_instance_index = mlx_image_to_window(data->mlx,
				get_image(tile_type, frame_index),
				(int32_t)(data->pixels_per_tile * column_index),
				(int32_t)(data->pixels_per_tile * row_index));
		if (frame_instance_index == -1)
		{
			// TODO: Delete previous images in ERROR_MLX42 cases?
			return (ft_set_error(ERROR_MLX42));
		}
		// tile_type->frames[frame_index]->instances[frame_instance_index].enabled = false;
		tile->frame_instances_indices[frame_index] = frame_instance_index;
		frame_index++;
	}
	return (SUCCESS);
}

STATIC t_success	malloc_tile_grid_cells(t_data *data)
{
	t_tile		***cells;
	uint32_t	row_index;

	cells = malloc(sizeof(t_tile **) * data->char_grid.height);
	if (cells == NULL)
		return (ft_set_error(ERROR_MALLOC));
	data->tile_grid.cells = cells;
	row_index = 0;
	while (row_index < data->char_grid.height)
	{
		cells[row_index] = malloc(sizeof(t_tile *) * data->char_grid.width);
		if (cells[row_index] == NULL)
		{
			// TODO: Free previously allocated rows.
			ft_free(&data->tile_grid.cells);
			return (ft_set_error(ERROR_MALLOC));
		}
		row_index++;
	}
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////

/* TODO:
 * Is this snippet from MLX42.h line 620 saying that doing
 * data->images->instances[n] could fail?
 *
 * NOTE: Keep in mind that the instance array gets reallocated, try to
 * to store the return value to the instance!
 * NOT the pointer! It will become invalid!
 */
t_success	sl_instantiate_tile_grid(t_data *data)
{
	uint32_t	column_index;
	uint32_t	row_index;

	if (malloc_tile_grid_cells(data) != SUCCESS)
		return (ft_get_error());
	row_index = 0;
	while (row_index < data->char_grid.height)
	{
		column_index = 0;
		while (column_index < data->char_grid.width)
		{
			instantiate_tile(column_index, row_index, data);
			column_index++;
		}
		row_index++;
	}
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
