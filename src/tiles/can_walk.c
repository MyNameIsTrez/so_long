/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   can_walk.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 18:55:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 12:42:45 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	can_walk(t_heading heading, t_tile *tile, t_data *data)
{
	t_i32	column;
	t_i32	row;
	size_t	index;

	column = sl_get_heading_column(heading, tile, data);
	row = sl_get_heading_row(heading, tile, data);
	if (sl_out_of_bounds(column, row, data))
		return (false);
	index = sl_get_index((size_t)column, (size_t)row, data);
	if (!is_tile_walkable(index, data))
		return (false);
	if (is_entity_in_way(index, data))
		return (false);
	return (true);
}

////////////////////////////////////////////////////////////////////////////////
