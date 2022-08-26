/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_players.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 16:08:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 16:59:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	reset_players(t_data *data)
{
	t_iterator	it;
	t_player	*player;
	t_entity	*entity;

	ft_init_it(&it);
	while (sl_iterate_players(&it, data) != FINISHED)
	{
		player = data->it.player;
		entity = player->entity;
		sl_change_frame(&entity->tile, 0);
		sl_set_tile_pos(&entity->tile, entity->tile.initial.index, data);
		entity->ticks_between_frame_changes = \
			PLAYER_TICKS_BETWEEN_FRAME_CHANGES;
		entity->ticks_between_updates = PLAYER_TICKS_BETWEEN_UPDATES;
		player->dead = false;
		player->dying = false;
		entity->animated = true;
	}
}

////////////////////////////////////////////////////////////////////////////////
