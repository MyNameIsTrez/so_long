/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_walkable.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:13:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 21:21:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	is_walkable(t_player *player, t_heading heading, t_data *data)
{
	t_tile	*tile;
	keys_t	*movement_keys;
	t_i32	column;
	t_i32	row;

	tile = &player->entity->tile;
	movement_keys = player->controls.movement_keys;
	column = sl_get_heading_column(heading, tile);
	row = sl_get_heading_row(heading, tile);
	return (can_walk(column, row, data));
}

////////////////////////////////////////////////////////////////////////////////
