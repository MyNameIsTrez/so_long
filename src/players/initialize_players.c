/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_players.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:05:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 18:06:40 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/initialize_players/sl_private_initialize_players.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_initialize_players(t_data *data)
{
	t_iterator	it;
	t_u8		character;
	t_player	player;

	data->players = ft_vector_new(sizeof(t_player));
	ft_init_it(&it);
	while (sl_iterate_entities(&it, data) != FINISHED)
	{
		character = data->it.entity->tile.tile_kind->character;
		if (ft_chr_in_str(character, PLAYER_CHARACTERS))
		{
			player.entity = data->it.entity;
			player.controls = get_player_controls(character);
			player.dead = false;
			player.dying = false;
			if (ft_vector_push(&data->players, &player) != OK)
				return (ERROR);
		}
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
