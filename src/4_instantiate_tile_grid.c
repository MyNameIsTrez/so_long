/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_instantiate_tile_grid.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 18:02:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/01 18:23:18 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_status	malloc_tile(t_tile_kind *tile_kind, t_tile **tile)
{
	*tile = malloc(sizeof(t_tile));
	if (*tile == NULL)
		return (ft_set_error(ERROR_MALLOC));
	return (sl_fill_tile_data(tile_kind, *tile));
}

STATIC t_tile_kind	*get_tile_kind(uint32_t column_index, uint32_t row_index, t_data *data)
{
	return (&data->tile_kinds[(unsigned char)sl_get_grid_character(column_index, row_index, data)]);
}

STATIC t_status	instantiate_tile(uint32_t column_index, uint32_t row_index,
			t_data *data)
{
	t_tile_kind*const	tile_kind = get_tile_kind(column_index, row_index, data);
	t_tile				*tile;

	if (malloc_tile(tile_kind, &data->tile_grid.cells[row_index][column_index]) != OK)
		return (ft_get_error());
	tile = data->tile_grid.cells[row_index][column_index];
	if (sl_initialize_instance_for_frames(tile, column_index, row_index,
			data) != OK)
		return (ft_get_error());
	return (OK);
}

STATIC t_status	callback_malloc_rows(uint32_t row_index, t_data *data)
{
	t_tile		***cells;

	cells = data->tile_grid.cells;
	cells[row_index] = malloc(sizeof(t_tile *) * data->char_grid.width);
	if (cells[row_index] == NULL)
	{
		// TODO: Free previously allocated rows.
		ft_free(&data->tile_grid.cells);
		return (ft_set_error(ERROR_MALLOC));
	}
	return (OK);
}

STATIC t_status	malloc_tile_grid_cells(t_data *data)
{
	t_tile		***cells;

	cells = malloc(sizeof(t_tile **) * data->char_grid.height);
	if (cells == NULL)
		return (ft_set_error(ERROR_MALLOC));
	data->tile_grid.cells = cells;
	if (sl_iterate_char_grid_height(callback_malloc_rows, data) != OK)
		return (ft_get_error());
	return (OK);
}

STATIC t_status	callback_instantiate_tile(uint32_t column_index,
			uint32_t row_index, t_data *data)
{
	if (!sl_is_entity(column_index, row_index, data))
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
