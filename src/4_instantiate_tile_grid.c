/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_instantiate_tile_grid.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 18:02:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/30 14:41:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_status	malloc_tile(t_tile_type *tile_type, t_tile **tile)
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

STATIC t_status	instantiate_tile(uint32_t column_index, uint32_t row_index,
			t_data *data)
{
	t_tile_type*const	tile_type = get_tile_type(column_index, row_index, data);
	t_tile				*tile;

	if (malloc_tile(tile_type, &data->tile_grid.cells[row_index][column_index]) != OK)
		return (ft_get_error());
	tile = data->tile_grid.cells[row_index][column_index];
	if (sl_initialize_instance_for_frames(tile, column_index, row_index,
			data) != OK)
		return (ft_get_error());
	return (OK);
}

STATIC t_status	malloc_tile_grid_cells(t_data *data)
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
	return (OK);
}

STATIC t_status	callback_instantiate_tile(uint32_t column_index,
			uint32_t row_index, t_data *data)
{
	if (!is_entity(column_index, row_index, data))
	{
		if (instantiate_tile(column_index, row_index, data) != OK)
		{
			// TODO: Free previous stuff.
			return (ft_get_error());
		}
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_tile_grid(t_data *data)
{
	if (malloc_tile_grid_cells(data) != OK)
		return (ft_get_error());
	if (sl_iterate_char_grid(callback_instantiate_tile, data) != OK)
		return (ft_get_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
