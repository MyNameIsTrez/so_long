/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_move_players.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 10:37:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 20:33:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/try_move_players/sl_private_try_move_players.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_try_move_players(t_data *data)
{
	t_player	*player;

	while (sl_iterate_players(data) != FINISHED)
	{
		player = data->it.player;
		// TODO: Use lookup table
		if (can_player_shift(player, HEADING_UP, data))
			shift_player(player, 0, -1, data);
		if (can_player_shift(player, HEADING_DOWN, data))
			shift_player(player, 0, 1, data);
		if (can_player_shift(player, HEADING_LEFT, data))
			shift_player(player, -1, 0, data);
		if (can_player_shift(player, HEADING_RIGHT, data))
			shift_player(player, 1, 0, data);
	}
}

////////////////////////////////////////////////////////////////////////////////
