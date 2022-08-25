/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_monsters.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 16:41:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 16:50:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	reset_monsters(t_data *data)
{
	t_iterator	it;
	t_monster	*monster;

	ft_init_it(&it);
	while (sl_iterate_monsters(&it, data) != FINISHED)
	{
		monster = data->it.monster;
		sl_change_frame(&monster->entity->tile, monster->entity->tile.initial.frame_index);
		sl_set_tile_pos(&monster->entity->tile, monster->entity->tile.initial.index, data);
		monster->entity->animated = true;
		monster->heading = HEADING_NONE;
		sl_set_monster_heading(monster, data);
	}
}

////////////////////////////////////////////////////////////////////////////////
