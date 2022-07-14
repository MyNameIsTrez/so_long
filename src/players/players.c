/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   players.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 10:37:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 16:58:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	shift_player(t_player *player, t_i32 x, t_i32 y, t_data *data)
{
	sl_shift_tile_pos(&player->entity->tile, x, y, data);
}

STATIC bool	is_entity_walkable(t_i32 column, t_i32 row, t_data *data)
{
	t_entity		*entity;
	t_u8	character;

	while (sl_iterate_entities(data) != FINISHED)
	{
		entity = data->it.entity;
		if (entity->tile.column_index != column
			|| entity->tile.row_index != row)
			continue ;
		character = entity->tile.tile_kind->character;
		if (!ft_chr_in_str(character, WALKABLE_CHARACTERS))
			return (false);
	}
	return (true);
}

STATIC bool	is_tile_walkable(t_i32 column, t_i32 row, t_data *data)
{
	t_u8		tile_character;

	data->it.column_index = column;
	data->it.row_index = row;
	tile_character = sl_get_tile_grid_character(data);
	return (ft_chr_in_str(tile_character, WALKABLE_CHARACTERS));
}

STATIC bool	is_walkable(t_player *player, keys_t key, t_data *data)
{
	t_tile		*tile;
	t_controls	*controls;
	t_i32		column;
	t_i32		row;

	tile = &player->entity->tile;
	controls = &player->controls;
	column = tile->column_index + sl_get_key_column_offset(key, controls);
	row = tile->row_index + sl_get_key_row_offset(key, controls);
	if (sl_out_of_bounds(column, row, data))
		return (false);
	return (is_tile_walkable(column, row, data)
		&& is_entity_walkable(column, row, data));
}

STATIC bool	can_autowalk(t_i32 frames_held)
{
	bool	held_long_enough;
	bool	is_autowalk_frame;

	held_long_enough = frames_held >= MIN_FRAMES_HELD_FOR_AUTOWALK;
	is_autowalk_frame = frames_held % FRAMES_BETWEEN_AUTOWALK == 0;
	return (held_long_enough && is_autowalk_frame);
}

STATIC bool	can_player_shift(t_player *player, keys_t key, t_data *data)
{
	t_i32	frames_held;
	bool		key_was_held;

	if (!mlx_is_key_down(data->mlx, key))
		return (false);
	frames_held = data->held_keys[key];
	key_was_held = frames_held > 0;
	if (key_was_held && !can_autowalk(frames_held))
		return (false);
	if (!is_walkable(player, key, data))
		return (false);
	return (true);
}

void	sl_try_move_players(t_data *data)
{
	t_player		*player;
	t_controls		*controls;

	while (sl_iterate_player_count(data) != FINISHED)
	{
		player = &data->players[data->it.player_index];
		controls = &player->controls;
		if (can_player_shift(player, controls->up_key, data))
			shift_player(player, 0, -1, data);
		if (can_player_shift(player, controls->down_key, data))
			shift_player(player, 0, 1, data);
		if (can_player_shift(player, controls->left_key, data))
			shift_player(player, -1, 0, data);
		if (can_player_shift(player, controls->right_key, data))
			shift_player(player, 1, 0, data);
	}
}

////////////////////////////////////////////////////////////////////////////////
