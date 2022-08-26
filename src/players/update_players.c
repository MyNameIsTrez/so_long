/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_players.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 15:45:32 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 18:25:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/update_players/sl_private_update_players.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_players(t_data *data)
{
	bool		all_players_dead;
	t_iterator	it;
	t_player	*player;
	t_entity	*entity;
	t_tile		*tile;

	all_players_dead = true;
	ft_init_it(&it);
	while (sl_iterate_players(&it, data) != FINISHED)
	{
		player = data->it.player;
		entity = player->entity;
		tile = &entity->tile;
		if (update_player(player, entity, tile, data))
			all_players_dead = false;
	}
	if (all_players_dead)
		sl_reset_level(data);
}

////////////////////////////////////////////////////////////////////////////////
