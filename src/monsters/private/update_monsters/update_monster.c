/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_monster.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 14:42:08 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 21:40:18 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_monster(t_monster *monster, t_data *data)
{
	t_heading	heading;
	t_tile		*tile;
	t_i32		column;
	t_i32		row;

	heading = monster->heading;
	if (heading == HEADING_NONE)
		sl_set_monster_heading(monster, data);
	heading = monster->heading;
	if (heading != HEADING_NONE)
	{
		tile = &monster->entity->tile;
		column = sl_get_heading_column(heading, tile);
		row = sl_get_heading_row(heading, tile);
		if (can_walk(column, row, data))
			sl_set_tile_pos(tile, (size_t)column, (size_t)row, data);
		else
			monster->heading = HEADING_NONE;
	}
}

////////////////////////////////////////////////////////////////////////////////
