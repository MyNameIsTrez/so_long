/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_player.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 15:49:53 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 12:20:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "update_player/sl_private_update_player.h"

////////////////////////////////////////////////////////////////////////////////

void	update_player(t_player *player, t_data *data)
{
	try_move(player, data);
	try_collect_collectible(player, data);
	try_walk_into_exit(player, data);
}

////////////////////////////////////////////////////////////////////////////////
