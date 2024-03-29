/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:50:14 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 17:30:04 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "instantiate_tile/sl_private_instantiate_tile.h"

////////////////////////////////////////////////////////////////////////////////

t_status	instantiate_tile(t_data *data)
{
	t_tile_kind	*tile_kind;
	t_tile		tile;

	tile_kind = sl_get_tile_grid_tile_kind(data);
	if (sl_fill_tile_data(&tile, tile_kind, data) != OK)
		return (ERROR);
	if (tile_kind->character == WALL_CHARACTER)
		tile.frame_index = get_wall_frame_index(&tile, data);
	if (sl_instantiate_tile_frames(&tile, data) != OK)
		return (ERROR);
	if (ft_vector_push(&data->tile_grid.cells, &tile) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
