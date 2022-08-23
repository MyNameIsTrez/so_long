/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_player_in_way.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:45:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 17:08:22 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	is_player_in_way(t_heading heading, t_tile *monster_tile, t_data *data)
{
	t_i32	column;
	t_i32	row;
	size_t	index;

	column = sl_get_heading_column(heading, monster_tile, data);
	row = sl_get_heading_row(heading, monster_tile, data);
	if (sl_out_of_bounds(column, row, data))
		return (false);
	index = sl_get_index((size_t)column, (size_t)row, data);


	t_iterator	it;
	t_player	*player;

	ft_init_it(&it);
	while (sl_iterate_players(&it, data) != FINISHED)
	{
		player = data->it.player;
		if (player->entity->tile.index == index)
			return (true);
	}
	return (false);
}

////////////////////////////////////////////////////////////////////////////////
