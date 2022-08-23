/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_death_state.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:19:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 16:41:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#if BONUS

bool	monster_in_way(size_t index, t_data *data)
{
	t_iterator	it;
	t_entity	*entity;
	t_u8		character;

	ft_init_it(&it);
	while (sl_iterate_entities(&it, data) != FINISHED)
	{
		entity = data->it.entity;
		if (entity->tile.index != index)
			continue ;
		character = entity->tile.tile_kind->character;
		if (character == MONSTER_CHARACTER)
			return (true);
	}
	return (false);
}

void	update_death_state(t_player *player, t_heading heading, t_data *data)
{
	t_tile		*tile;
	t_i32		column;
	t_i32		row;
	size_t		index;

	tile = &player->entity->tile;

	column = sl_get_heading_column(heading, tile, data);
	row = sl_get_heading_row(heading, tile, data);
	if (sl_out_of_bounds(column, row, data))
		return ;
	index = sl_get_index((size_t)column, (size_t)row, data);
	if (!sl_is_tile_walkable(index, data))
		return ;
	if (monster_in_way(index, data))
		player->dead = true;
}

#endif

////////////////////////////////////////////////////////////////////////////////
