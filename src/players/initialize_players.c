/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_players.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:05:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/04 14:12:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "initialize_players_utils/sl_initialize_players_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_initialize_players(t_data *data)
{
	t_u8		character;
	t_player	player;

	data->players = ft_vector_new(sizeof(t_player));
	while (sl_iterate_entities(data) != FINISHED)
	{
		character = data->it.entity->tile.tile_kind->character;
		if (ft_chr_in_str(character, PLAYER_CHARACTERS))
		{
			player.entity = data->it.entity;
			player.controls = get_player_controls(character);
			ft_vector_push(&data->players, &player);
		}
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
