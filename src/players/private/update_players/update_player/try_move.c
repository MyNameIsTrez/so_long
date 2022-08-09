/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_move.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 10:37:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 16:10:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "try_move/sl_private_try_move.h"

////////////////////////////////////////////////////////////////////////////////

void	try_move(t_player *player, t_data *data)
{
	if (can_shift(player, HEADING_UP, data))
		shift(player, 0, -1, data);
	if (can_shift(player, HEADING_DOWN, data))
		shift(player, 0, 1, data);
	if (can_shift(player, HEADING_LEFT, data))
		shift(player, -1, 0, data);
	if (can_shift(player, HEADING_RIGHT, data))
		shift(player, 1, 0, data);
}

////////////////////////////////////////////////////////////////////////////////
