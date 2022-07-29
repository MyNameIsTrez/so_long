/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 11:25:47 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_u8	sl_get_char_grid_character(t_data *data)
{
	size_t	row_index;
	size_t	column_index;

	row_index = data->it.row_index;
	column_index = data->it.column_index;
	return ((t_u8)data->char_grid.cells[row_index][column_index]);
}

t_u8	sl_get_tile_grid_character(t_data *data)
{
	t_tile	*tile;

	tile = &data->tile_grid.cells[data->it.row_index][data->it.column_index];
	return (tile->tile_kind->character);
}

////////////////////////////////////////////////////////////////////////////////
