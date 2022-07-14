/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   6_instantiate_players.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 16:48:50 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 15:35:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_controls	get_players_controls(t_u32 player_index)
{
	static const t_controls	players_controls[] = {
	{.up_key = PLAYER_1_UP_KEY, .down_key = PLAYER_1_DOWN_KEY,
		.left_key = PLAYER_1_LEFT_KEY, .right_key = PLAYER_1_RIGHT_KEY},
	{.up_key = PLAYER_2_UP_KEY, .down_key = PLAYER_2_DOWN_KEY,
		.left_key = PLAYER_2_LEFT_KEY, .right_key = PLAYER_2_RIGHT_KEY},
	};

	return (players_controls[player_index]);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_players(t_data *data)
{
	t_u32	player_index;
	t_player	*players;
	t_player	*player;

	player_index = 0;
	players = data->players;
	sl_reset_iterate_entities(data);
	while (sl_iterate_entities(data) != FINISHED)
	{
		if (data->it.entity->tile.tile_kind->character == PLAYER_CHARACTER)
		{
			if (player_index >= MAX_PLAYER_COUNT)
				return (sl_set_error(SL_ERROR_TOO_MANY_PLAYERS));
			player = &players[player_index];
			player->entity = data->it.entity;
			player->controls = get_players_controls(player_index);
			player_index++;
		}
	}
	data->player_count = player_index;
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
