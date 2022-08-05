/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_monsters.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 14:25:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 22:09:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/instantiate_monsters/sl_private_instantiate_monsters.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_monsters(t_data *data)
{
	t_iterator	it;
	t_u8		character;

	data->monsters = ft_vector_new(sizeof(t_monster));
	ft_init_it(&it);
	while (sl_iterate_entities(&it, data) != FINISHED)
	{
		character = data->it.entity->tile.tile_kind->character;
		if (character == MONSTER_CHARACTER)
			if (instantiate_monster(data) != OK)
				return (ERROR);
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
