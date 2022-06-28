/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_instantiate_tile_grid.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 18:02:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/28 16:07:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_success	malloc_tile(t_tile_type *tile_type, t_tile **tile)
{
	*tile = malloc(sizeof(t_tile));
	if (*tile == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (sl_fill_tile_data(tile_type, *tile));
}

STATIC t_tile_type	*get_tile_type(uint32_t column_index, uint32_t row_index, t_data *data)
{
	return (&data->tile_types[(unsigned char)sl_get_grid_character(column_index, row_index, data)]);
}

STATIC t_success	instantiate_tile(uint32_t column_index, uint32_t row_index,
			t_data *data)
{
	t_tile_type*const	tile_type = get_tile_type(column_index, row_index, data);
	t_tile				*tile;

	if (malloc_tile(tile_type, &data->tile_grid.cells[row_index][column_index]) != SUCCESS)
		return (ft_get_error());
	tile = data->tile_grid.cells[row_index][column_index];
	if (sl_initialize_instance_for_frames(tile, column_index, row_index,
			data) != SUCCESS)
		return (ft_get_error());
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
