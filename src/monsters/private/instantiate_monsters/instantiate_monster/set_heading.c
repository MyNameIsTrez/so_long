/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_heading.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 18:45:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 19:23:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "set_heading/sl_private_set_heading.h"

////////////////////////////////////////////////////////////////////////////////

void	set_heading(t_monster *monster, t_data *data)
{
	size_t		monster_column;
	size_t		monster_row;
	t_heading	heading;
	t_i32		column;
	t_i32		row;

	monster_column = monster->entity->tile.column_index;
	monster_row = monster->entity->tile.row_index;
	while (sl_iterate_heading(data) != FINISHED)
	{
		heading = data->it.heading;
		column = (t_i32)monster_column + get_heading_column_offset(heading);
		row = (t_i32)monster_row + get_heading_row_offset(heading);
		if (can_walk(column, row, data))
		{
			monster->heading = heading;
			sl_reset_iterate_heading(data);
			return ;
		}
	}
	monster->heading = HEADING_NONE;
}

////////////////////////////////////////////////////////////////////////////////
