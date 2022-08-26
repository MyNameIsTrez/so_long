/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_collectibles.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 16:34:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 17:29:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/instantiate_collectibles/\
sl_private_instantiate_collectibles.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_collectibles(t_data *data)
{
	t_iterator	it;
	t_u8		character;

	data->collectibles = ft_vector_new(sizeof(t_collectible));
	ft_init_it(&it);
	while (sl_iterate_entities(&it, data) != FINISHED)
	{
		character = data->it.entity->tile.tile_kind->character;
		if (character == COLLECTIBLE_CHARACTER)
			if (instantiate_collectible(data) != OK)
				return (ERROR);
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
