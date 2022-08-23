/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_monster_heading.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 18:45:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 12:46:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_set_monster_heading(t_monster *monster, t_data *data)
{
	t_iterator	it;
	t_heading	heading;
	t_tile		*monster_tile;

	ft_init_it(&it);
	while (sl_iterate_headings(&it, data) != FINISHED)
	{
		heading = data->it.heading;
		monster_tile = &monster->entity->tile;
		if (can_walk(heading, monster_tile, data))
		{
			monster->heading = heading;
			return ;
		}
	}
	monster->heading = HEADING_NONE;
}

////////////////////////////////////////////////////////////////////////////////
