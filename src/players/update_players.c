/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_players.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 15:45:32 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 15:55:13 by sbos          ########   odam.nl         */
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

	all_players_dead = true;
	ft_init_it(&it);
	while (sl_iterate_players(&it, data) != FINISHED)
	{
		player = data->it.player;
		if (player->dying && !player->dead)
		{
			all_players_dead = false;
			if (player->entity->ticks_between_updates != 1)
				sl_change_frame(&player->entity->tile, 4);
			player->entity->ticks_between_frame_changes = 1;
			player->entity->ticks_between_updates = 1;
			if (player->entity->tile.frame_index == player->entity->tile.tile_kind->frame_count - 1)
				player->dead = true;
		}
		else if (player->dead)
			player->entity->enabled = false;
		else if (!player->dead)
		{
			all_players_dead = false;
			if (player->entity->tile.frame_index == 4)
				sl_change_frame(&player->entity->tile, 0);
			update_player(player, data);
		}
	}
	if (all_players_dead)
		sl_reset_level(data);
}

////////////////////////////////////////////////////////////////////////////////
