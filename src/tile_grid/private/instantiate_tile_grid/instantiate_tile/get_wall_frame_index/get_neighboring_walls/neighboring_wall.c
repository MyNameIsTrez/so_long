/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   neighboring_wall.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 14:09:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 18:20:45 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	neighboring_wall(t_i32 column_offset, t_i32 row_offset, t_tile *tile,
			t_data *data)
{
	size_t	tile_column;
	size_t	tile_row;
	size_t	column;
	size_t	row;
	size_t	index;

	tile_column = sl_get_tile_column(tile, data);
	tile_row = sl_get_tile_row(tile, data);
	if (column_offset == -1 && tile_column <= 0)
		return (true);
	if (row_offset == -1 && tile_row <= 0)
		return (true);
	if (column_offset == 1 && tile_column >= data->char_grid.width - 1)
		return (true);
	if (row_offset == 1 && tile_row >= data->char_grid.height - 1)
		return (true);
	// TODO: Refactor this (column; row) -> index mess
	column = (size_t)((t_i32)tile_column + column_offset);
	row = (size_t)((t_i32)tile_row + row_offset);
	index = column + row * data->char_grid.width;
	return (data->char_grid.cells[index] == WALL_CHARACTER);
}

////////////////////////////////////////////////////////////////////////////////
