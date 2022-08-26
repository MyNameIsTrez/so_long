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
		if (player->dying && !player->dead)
		{
			all_players_dead = false;
			if (entity->ticks_between_updates != 1)
				sl_change_frame(tile, 4);
			entity->ticks_between_frame_changes = 1;
			entity->ticks_between_updates = 1;
			if (tile->frame_index == tile->tile_kind->frame_count - 1)
				player->dead = true;
		}
		else if (player->dead)
		{
			sl_set_tile_pos(tile, 0, data);
			entity->animated = false;
		}
		else if (!player->dead)
		{
			all_players_dead = false;
			if (tile->frame_index == 4)
				sl_change_frame(tile, 0);
			update_player(player, data);
		}
	}
	if (all_players_dead)
		sl_reset_level(data);
}

////////////////////////////////////////////////////////////////////////////////
