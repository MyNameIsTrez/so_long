/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_monster_heading.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 18:45:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 18:33:37 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/sl_private_monsters.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_set_monster_heading(t_monster *monster, t_data *data)
{
	t_tile		*monster_tile;
	t_iterator	it;
	t_heading	heading;

	if (monster->heading == HEADING_NONE)
		monster->heading = HEADING_UP;
	monster_tile = &monster->entity->tile;
	ft_init_it(&it);
	while (sl_iterate_headings(&it, data) != FINISHED)
	{
		heading = (monster->heading + data->it.heading) % 4;
		if (is_player_in_way(heading, monster_tile, data))
			kill_player(heading, monster_tile, data);
		if (sl_can_walk(heading, monster_tile, data))
		{
			monster->heading = heading;
			return ;
		}
	}
	monster->heading = HEADING_NONE;
}

////////////////////////////////////////////////////////////////////////////////
