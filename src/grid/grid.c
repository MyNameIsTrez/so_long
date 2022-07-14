/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 11:25:47 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 11:58:05 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

unsigned char	sl_get_char_grid_character(t_data *data)
{
	return ((unsigned char)data->char_grid.cells[data->it.row_index][data->it.column_index]);
}

unsigned char	sl_get_tile_grid_character(t_data *data)
{
	t_tile	*tile;

	tile = data->tile_grid.cells[data->it.row_index][data->it.column_index];
	return (tile->tile_kind->character);
}

////////////////////////////////////////////////////////////////////////////////
