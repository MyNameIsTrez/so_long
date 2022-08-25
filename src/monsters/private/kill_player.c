/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:42:47 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 18:55:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	kill_player(t_heading heading, t_tile *monster_tile, t_data *data)
{
	size_t		index;
	t_iterator	it;
	t_player	*player;

	index = sl_get_heading_index(heading, monster_tile, data);
	ft_init_it(&it);
	while (sl_iterate_players(&it, data) != FINISHED)
	{
		player = data->it.player;
		if (player->entity->tile.index == index)
		{
			sl_start_player_dying(player);
			return ;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
