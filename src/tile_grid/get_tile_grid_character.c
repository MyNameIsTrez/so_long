/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_tile_grid_character.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 11:25:47 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 16:17:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_u8	sl_get_tile_grid_character(t_data *data)
{
	t_tile	*tile;

	tile = &data->tile_grid.cells[data->it.row][data->it.column];
	return (tile->tile_kind->character);
}

////////////////////////////////////////////////////////////////////////////////
