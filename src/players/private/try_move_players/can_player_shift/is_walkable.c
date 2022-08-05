/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_walkable.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:13:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 19:25:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "is_walkable/sl_private_is_walkable.h"

////////////////////////////////////////////////////////////////////////////////

bool	is_walkable(t_player *player, keys_t key, t_data *data)
{
	t_tile	*tile;
	keys_t	*movement_keys;
	t_i32	column;
	t_i32	row;

	tile = &player->entity->tile;
	movement_keys = player->controls.movement_keys;
	column = (t_i32)tile->column_index + get_key_column_offset(key, movement_keys);
	row = (t_i32)tile->row_index + get_key_row_offset(key, movement_keys);
	return (can_walk(column, row, data));
}

////////////////////////////////////////////////////////////////////////////////
