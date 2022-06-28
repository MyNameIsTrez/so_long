/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   6_instantiate_players.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 16:48:50 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/28 17:26:53 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_controls	get_players_controls(uint32_t player_index)
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

t_success	sl_instantiate_players(t_data *data)
{
	uint32_t	player_index;
	t_player	*players;
	t_player	*player;
	t_list		*entities;
	t_entity	*entity;

	entities = data->entities;
	player_index = 0;
	players = data->players;
	while (entities != NULL)
	{
		entity = entities->content;
		if (entity->tile.tile_type->character == PLAYER_CHARACTER)
		{
			if (player_index >= MAX_PLAYER_COUNT)
				return (ft_set_error(ERROR_TOO_MANY_PLAYERS));
			player = &players[player_index];
			player->entity = entity;
			player->controls = get_players_controls(player_index);
			player_index++;
		}
		entities = entities->next;
	}
	data->player_count = player_index;
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
