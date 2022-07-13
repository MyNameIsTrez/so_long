/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   players.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 10:37:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/13 16:07:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	shift_player(t_player *player, int32_t x, int32_t y, t_data *data)
{
	sl_shift_tile_pos(&player->entity->tile, x, y, data);
}

STATIC bool	is_walkable(t_player *player, keys_t key, t_data *data)
{
	const t_tile		*tile = &player->entity->tile;
	t_controls*const	controls = &player->controls;
	const int32_t		column = (int32_t)tile->column_index + \
									sl_get_key_column_offset(key, controls);
	const int32_t		row = (int32_t)tile->row_index + \
									sl_get_key_row_offset(key, controls);
	char				tile_character;

	if (sl_out_of_bounds(column, row, data))
		return (false);
	data->t.column_index = (uint32_t)column;
	data->t.row_index = (uint32_t)row;
	tile_character = data->char_grid.cells[row][column];
	return (ft_chr_in_str(tile_character, WALKABLE_CHARACTERS));
}

STATIC bool	can_autowalk(uint32_t frames_held)
{
	const bool	held_long_enough = frames_held >= MIN_FRAMES_HELD_FOR_AUTOWALK;
	const bool	is_autowalk_frame = frames_held % FRAMES_BETWEEN_AUTOWALK == 0;

	return (held_long_enough && is_autowalk_frame);
}

STATIC bool	can_player_shift(t_player *player, keys_t key, t_data *data)
{
	uint32_t	frames_held;
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
		player = &data->players[data->t.player_index];
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
