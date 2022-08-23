/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_monster_heading.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 18:45:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 16:29:14 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	set_monster_heading(t_monster *monster, t_data *data)
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
		if (can_walk(heading, monster_tile, data))
		{
			monster->heading = heading;
			return ;
		}
	}
	monster->heading = HEADING_NONE;
}

////////////////////////////////////////////////////////////////////////////////
