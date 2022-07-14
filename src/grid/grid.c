/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 11:25:47 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 15:32:08 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_u8	sl_get_char_grid_character(t_data *data)
{
	return ((t_u8)data->char_grid.cells[data->it.row_index][data->it.column_index]);
}

t_u8	sl_get_tile_grid_character(t_data *data)
{
	t_tile	*tile;

	tile = data->tile_grid.cells[data->it.row_index][data->it.column_index];
	return (tile->tile_kind->character);
}

////////////////////////////////////////////////////////////////////////////////
