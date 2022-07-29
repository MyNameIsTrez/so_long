/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_players.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:05:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 20:05:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "initialize_players_utils/sl_initialize_players_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_initialize_players(t_data *data)
{
	t_i32		player_index;
	t_player	player;

	player_index = 0;
	data->players = ft_vector_new(sizeof(t_player));
	while (sl_iterate_entities(data) != FINISHED)
	{
		if (data->it.entity->tile.tile_kind->character == PLAYER_CHARACTER)
		{
			if (player_index >= MAX_PLAYER_COUNT)
				return (sl_set_error(SL_ERROR_TOO_MANY_PLAYERS));
			player.entity = data->it.entity;
			player.controls = get_player_controls(player_index);
			ft_vector_push(&data->players, &player);
			player_index++;
		}
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
