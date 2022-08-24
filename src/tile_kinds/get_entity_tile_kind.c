/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_entity_tile_kind.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 17:32:08 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 14:46:58 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_tile_kind	*sl_get_entity_tile_kind(t_data *data)
{
	t_u8		character;
	t_iterator	it;
	t_tile_kind	*tile_kind;

	character = sl_get_char_grid_character(data);
	ft_init_it(&it);
	while (sl_iterate_tile_kinds(&it, data) != FINISHED)
	{
		tile_kind = data->it.tile_kind;
		if (tile_kind->character == character && tile_kind->is_entity)
			return (tile_kind);
	}
	return (NULL);
}

////////////////////////////////////////////////////////////////////////////////
