/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_monster_heading.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 18:45:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 11:55:41 by sbos          ########   odam.nl         */
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
	t_i32		column;
	t_i32		row;

	ft_init_it(&it);
	while (sl_iterate_headings(&it, data) != FINISHED)
	{
		heading = data->it.heading;
		monster_tile = &monster->entity->tile;
		column = sl_get_heading_column(heading, monster_tile, data);
		row = sl_get_heading_row(heading, monster_tile, data);
		if (can_walk(column, row, data))
		{
			monster->heading = heading;
			return ;
		}
	}
	monster->heading = HEADING_NONE;
}

////////////////////////////////////////////////////////////////////////////////
