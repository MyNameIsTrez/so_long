/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_monsters.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 15:57:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 21:15:33 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/update_monsters/sl_private_update_monsters.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_monsters(t_data *data)
{
	t_monster	*monster;
	t_entity	*entity;

	while (sl_iterate_monsters(data) != FINISHED)
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
