/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_move_players.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 10:37:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:37:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "try_move_players_utils/sl_try_move_players_utils.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_try_move_players(t_data *data)
{
	t_player	*player;

	while (sl_iterate_players(data) != FINISHED)
	{
		player = data->it.player;
		// TODO: Use lookup table
		if (can_player_shift(player, UP_MOVEMENT_KEY_INDEX, data))
			shift_player(player, 0, -1, data);
		if (can_player_shift(player, DOWN_MOVEMENT_KEY_INDEX, data))
			shift_player(player, 0, 1, data);
		if (can_player_shift(player, LEFT_MOVEMENT_KEY_INDEX, data))
			shift_player(player, -1, 0, data);
		if (can_player_shift(player, RIGHT_MOVEMENT_KEY_INDEX, data))
			shift_player(player, 1, 0, data);
	}
}

////////////////////////////////////////////////////////////////////////////////
