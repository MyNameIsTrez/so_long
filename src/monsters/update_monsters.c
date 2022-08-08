/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_monsters.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 15:57:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 16:57:21 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/update_monsters/sl_private_update_monsters.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_monsters(t_data *data)
{
	t_iterator	it;
	t_monster	*monster;
	t_entity	*entity;

	ft_init_it(&it);
	while (sl_iterate_monsters(&it, data) != FINISHED)
	{
		monster = data->it.monster;
		entity = monster->entity;
		if (entity->ticks_since_last_update > \
			entity->ticks_between_updates)
		{
			sl_update_monster(monster, data);
			entity->ticks_since_last_update = 0;
		}
		else
			entity->ticks_since_last_update++;
	}
}

////////////////////////////////////////////////////////////////////////////////
