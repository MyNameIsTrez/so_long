/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_player.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 15:49:53 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 12:20:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "update_player/sl_private_update_player.h"

////////////////////////////////////////////////////////////////////////////////

bool	update_player(t_player *player, t_entity *entity, t_tile *tile,
			t_data *data)
{
	bool	player_alive;

	player_alive = false;
	if (player->dying && !player->dead)
	{
		player_alive = true;
		dying(entity, tile, player);
	}
	else if (player->dead)
	{
		sl_set_tile_pos(tile, 0, data);
		entity->animated = false;
	}
	else if (!player->dead)
	{
		player_alive = true;
		if (tile->frame_index == 4)
			sl_change_frame(tile, 0);
		update_alive_player(player, data);
	}
	return (player_alive);
}

////////////////////////////////////////////////////////////////////////////////
