/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_monsters.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 14:25:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/04 16:07:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_monsters(t_data *data)
{
	t_u8		character;
	t_monster	monster;

	data->monsters = ft_vector_new(sizeof(t_monster));
	while (sl_iterate_entities(data) != FINISHED)
	{
		character = data->it.entity->tile.tile_kind->character;
		if (character == MONSTER_CHARACTER)
		{
			monster.entity = data->it.entity;
			ft_vector_push(&data->monsters, &monster);
		}
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
