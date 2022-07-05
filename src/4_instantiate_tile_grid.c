/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   4_instantiate_tile_grid.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 18:02:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/05 16:15:46 by sbos          ########   odam.nl         */
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

STATIC t_tile_kind	*get_tile_kind(t_data *data)
{
	return (&data->tile_kinds[sl_get_grid_character(data)]);
}

STATIC t_status	instantiate_tile(t_data *data)
{
	t_tile_kind*const	tile_kind = get_tile_kind(data);
	t_tile				*tile;

	if (malloc_tile(tile_kind, &data->tile_grid.cells[data->t.row_index][data->t.column_index]) != OK)
		return (ft_get_error());
	tile = sl_get_tile(data);
	if (sl_instance_tile_frames(tile, data) != OK)
		return (ft_get_error());
	return (OK);
}

STATIC t_status	malloc_rows(t_data *data)
{
	t_tile		***cells;

	cells = data->tile_grid.cells;
	cells[data->t.row_index] = malloc(sizeof(t_tile *) * data->t.char_grid.width);
	if (cells[data->t.row_index] == NULL)
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

	cells = malloc(sizeof(t_tile **) * data->t.char_grid.height);
	if (cells == NULL)
		return (ft_set_error(ERROR_MALLOC));
	data->tile_grid.cells = cells;
	sl_iterate_char_grid_height(data, true);
	while (sl_iterate_char_grid_height(data, false) != FINISHED)
		if (malloc_rows(data) != OK)
			return (ft_get_error());
	return (OK);
}

STATIC t_status	try_instantiate_tile(t_data *data)
{
	if (!sl_is_entity(data))
	{
		if (instantiate_tile(data) != OK)
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
	sl_iterate_char_grid(data, true);
	while (sl_iterate_char_grid(data, false) != FINISHED)
		if (try_instantiate_tile(data) != OK)
			return (ft_get_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
