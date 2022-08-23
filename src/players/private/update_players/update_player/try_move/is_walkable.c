/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_walkable.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:13:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/22 17:49:43 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	is_walkable(t_player *player, t_heading heading, t_data *data)
{
	t_tile	*tile;
	t_i32	column;
	t_i32	row;

	tile = &player->entity->tile;
	column = sl_get_heading_column(heading, tile, data);
	row = sl_get_heading_row(heading, tile, data);
	return (can_walk(column, row, data));
}

////////////////////////////////////////////////////////////////////////////////
