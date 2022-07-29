/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_walkable.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:13:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:41:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sl_try_move_players_utils.h"

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
	if (sl_out_of_bounds(column, row, data))
		return (false);
	return (is_tile_walkable((size_t)column, (size_t)row, data)
		&& is_entity_walkable((size_t)column, (size_t)row, data));
}

////////////////////////////////////////////////////////////////////////////////
