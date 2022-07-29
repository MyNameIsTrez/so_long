/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_entity_walkable.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:19:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:40:24 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	is_entity_walkable(size_t column, size_t row, t_data *data)
{
	t_entity	*entity;
	t_u8		character;

	while (sl_iterate_entities(data) != FINISHED)
	{
		entity = data->it.entity;
		if (entity->tile.column_index != column
			|| entity->tile.row_index != row)
			continue ;
		character = entity->tile.tile_kind->character;
		if (!ft_chr_in_str(character, WALKABLE_CHARACTERS))
		{
			sl_reset_iterate_entities(data);
			return (false);
		}
	}
	return (true);
}

////////////////////////////////////////////////////////////////////////////////
