/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dying.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 20:15:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 20:15:51 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	dying(t_entity *entity, t_tile *tile, t_player *player)
{
	if (entity->ticks_between_frame_changes != 1)
		sl_change_frame(tile, 4);
	entity->ticks_between_frame_changes = 1;
	if (tile->frame_index == tile->tile_kind->frame_count - 1)
		player->dead = true;
}

////////////////////////////////////////////////////////////////////////////////
