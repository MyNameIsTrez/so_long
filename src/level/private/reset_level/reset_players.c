/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_players.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 16:08:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 16:40:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	reset_players(t_data *data)
{
	t_iterator	it;
	t_player	*player;

	ft_init_it(&it);
	while (sl_iterate_players(&it, data) != FINISHED)
	{
		player = data->it.player;
		sl_change_frame(&player->entity->tile, player->entity->tile.initial.frame_index);
		sl_set_tile_pos(&player->entity->tile, player->entity->tile.initial.index, data);
		player->entity->ticks_between_frame_changes = PLAYER_TICKS_BETWEEN_FRAME_CHANGES;
		player->entity->ticks_between_updates = PLAYER_TICKS_BETWEEN_UPDATES;
		player->dead = false;
		player->dying = false;
		player->entity->animated = true;
	}
}

////////////////////////////////////////////////////////////////////////////////
