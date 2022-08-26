/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_add_neighbor.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 20:40:28 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 20:40:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	try_add_neighbor(t_heading heading, t_tile *tile,
				t_tile ***visit_stack, bool *visited, t_data *data)
{
	size_t	index;
	t_tile	*neighbor_tile;
	t_u8	neighbor_tile_character;

	if (!sl_try_get_index(&index, heading, tile, data))
		return (OK);
	if (visited[index])
		return (OK);
	neighbor_tile = &data->tile_grid.cells[index];
	neighbor_tile_character = neighbor_tile->tile_kind->character;
	if (!ft_chr_in_str(neighbor_tile_character,
			WALKABLE_CHARACTERS ENTITY_CHARACTERS))
		return (OK);
	if (ft_vector_push(visit_stack, &neighbor_tile) != OK)
		return (ERROR);
	visited[index] = true;
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
