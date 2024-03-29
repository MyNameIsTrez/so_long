/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_player_dying.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 18:44:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 18:46:23 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_start_player_dying(t_player *player)
{
	player->entity->tile.index = 0;
	player->dying = true;
}

////////////////////////////////////////////////////////////////////////////////
