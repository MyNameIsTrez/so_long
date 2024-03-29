/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hide_and_disable_entity.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 16:41:50 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 17:31:48 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_hide_and_disable_entity(t_entity *entity)
{
	t_tile	*tile;

	tile = &entity->tile;
	sl_get_frame_instance(tile, tile->frame_index)->enabled = false;
	entity->animated = false;
}

////////////////////////////////////////////////////////////////////////////////
