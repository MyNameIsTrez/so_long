/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_monster.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 14:42:08 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 18:44:58 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_monster(t_monster *monster, t_data *data)
{
	t_tile		*tile;
	t_i32		column;
	t_i32		row;

	if (monster->heading == HEADING_NONE)
		sl_set_monster_heading(monster, data);
	if (monster->heading != HEADING_NONE)
	{
		tile = &monster->entity->tile;
		column = sl_get_heading_column(monster->heading, tile, data);
		row = sl_get_heading_row(monster->heading, tile, data);
		if (!can_walk(column, row, data))
			sl_set_monster_heading(monster, data);
		if (monster->heading != HEADING_NONE)
		{
			column = sl_get_heading_column(monster->heading, tile, data);
			row = sl_get_heading_row(monster->heading, tile, data);
			sl_set_tile_pos(tile, sl_get_index((size_t)column, (size_t)row, data), data);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
