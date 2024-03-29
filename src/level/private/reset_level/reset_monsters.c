/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_monsters.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 16:41:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 16:59:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	reset_monsters(t_data *data)
{
	t_iterator	it;
	t_monster	*monster;
	t_entity	*entity;

	ft_init_it(&it);
	while (sl_iterate_monsters(&it, data) != FINISHED)
	{
		monster = data->it.monster;
		entity = monster->entity;
		sl_change_frame(&entity->tile, 0);
		sl_set_tile_pos(&entity->tile, entity->tile.initial.index, data);
		entity->animated = true;
		monster->heading = HEADING_NONE;
		sl_set_monster_heading(monster, data);
	}
}

////////////////////////////////////////////////////////////////////////////////
