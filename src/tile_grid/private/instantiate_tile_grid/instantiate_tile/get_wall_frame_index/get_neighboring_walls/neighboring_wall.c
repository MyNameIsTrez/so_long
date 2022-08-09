/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   neighboring_wall.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 14:09:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 14:09:13 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	neighboring_wall(t_i32 column_offset, t_i32 row_offset, t_tile *tile,
			t_data *data)
{
	size_t	column;
	size_t	row;

	if (column_offset == -1 && tile->column_index <= 0)
		return (true);
	if (row_offset == -1 && tile->row_index <= 0)
		return (true);
	if (column_offset == 1 && tile->column_index >= data->char_grid.width - 1)
		return (true);
	if (row_offset == 1 && tile->row_index >= data->char_grid.height - 1)
		return (true);
	column = (size_t)((t_i32)tile->column_index + column_offset);
	row = (size_t)((t_i32)tile->row_index + row_offset);
	return (data->char_grid.cells[row][column] == WALL_CHARACTER);
}

////////////////////////////////////////////////////////////////////////////////
