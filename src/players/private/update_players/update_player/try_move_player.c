/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_move_player.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 10:37:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 16:02:14 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "try_move_player/sl_private_try_move_player.h"

////////////////////////////////////////////////////////////////////////////////

void	try_move_player(t_player *player, t_data *data)
{
	if (can_player_shift(player, HEADING_UP, data))
		shift_player(player, 0, -1, data);
	if (can_player_shift(player, HEADING_DOWN, data))
		shift_player(player, 0, 1, data);
	if (can_player_shift(player, HEADING_LEFT, data))
		shift_player(player, -1, 0, data);
	if (can_player_shift(player, HEADING_RIGHT, data))
		shift_player(player, 1, 0, data);
}

////////////////////////////////////////////////////////////////////////////////
