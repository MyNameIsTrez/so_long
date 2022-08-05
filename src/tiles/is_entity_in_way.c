/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_entity_in_way.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:19:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 22:11:13 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	is_entity_in_way(size_t column, size_t row, t_data *data)
{
	t_iterator	it;
	t_entity	*entity;
	t_u8		character;

	ft_init_it(&it);
	while (sl_iterate_entities(&it, data) != FINISHED)
	{
		entity = data->it.entity;
		if (entity->tile.column_index != column
			|| entity->tile.row_index != row)
			continue ;
		character = entity->tile.tile_kind->character;
		if (!ft_chr_in_str(character, WALKABLE_CHARACTERS))
			return (true);
	}
	return (false);
}

////////////////////////////////////////////////////////////////////////////////
