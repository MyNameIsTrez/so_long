/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_monster.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 14:42:08 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 12:45:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_monster(t_monster *monster, t_data *data)
{
	t_tile		*tile;

	if (monster->heading == HEADING_NONE)
		sl_set_monster_heading(monster, data);
	if (monster->heading != HEADING_NONE)
	{
		tile = &monster->entity->tile;
		if (!can_walk(monster->heading, tile, data))
			sl_set_monster_heading(monster, data);
		if (monster->heading != HEADING_NONE)
			shift_tile_pos_to_heading(tile, monster->heading, data);
	}
}

////////////////////////////////////////////////////////////////////////////////
