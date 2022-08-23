/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_monster.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 14:42:08 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 17:47:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_private_monsters.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_monster(t_monster *monster, t_data *data)
{
	t_tile		*monster_tile;

	if (monster->heading == HEADING_NONE)
		set_monster_heading(monster, data);
	if (monster->heading != HEADING_NONE)
	{
		monster_tile = &monster->entity->tile;
		if (!sl_can_walk(monster->heading, monster_tile, data))
		{
			if (is_player_in_way(monster->heading, monster_tile, data))
				kill_player(monster->heading, monster_tile, data);
			set_monster_heading(monster, data);
		}
		if (monster->heading != HEADING_NONE)
			sl_shift_tile_pos_to_heading(monster_tile, monster->heading, data);
	}
}

////////////////////////////////////////////////////////////////////////////////
