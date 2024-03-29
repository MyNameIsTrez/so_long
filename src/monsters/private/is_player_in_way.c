/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_player_in_way.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:45:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 19:03:42 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	is_player_in_way(t_heading heading, t_tile *monster_tile, t_data *data)
{
	size_t		index;
	t_iterator	it;
	t_player	*player;

	if (!sl_try_get_index(&index, heading, monster_tile, data))
		return (false);
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
