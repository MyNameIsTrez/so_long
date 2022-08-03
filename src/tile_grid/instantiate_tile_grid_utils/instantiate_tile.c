/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:50:14 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 16:27:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sl_instantiate_tile_grid_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	instantiate_tile(t_data *data)
{
	t_tile_kind	*tile_kind;
	t_tile		tile;

	tile_kind = get_tile_grid_tile_kind(data);
	if (sl_fill_tile_data(&tile, tile_kind, data) != OK)
		return (ERROR);
	if (sl_instantiate_tile_frames(&tile, data) != OK)
		return (ERROR);
	ft_vector_push(&data->tile_grid.cells[data->it.row_index], &tile);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
