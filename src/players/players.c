/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   players.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 10:37:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/12 10:38:15 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC bool	can_autowalk(uint32_t frames_held)
{
	const bool	held_long_enough = frames_held >= MIN_FRAMES_HELD_FOR_AUTOWALK;
	const bool	is_autowalk_frame = frames_held % FRAMES_BETWEEN_AUTOWALK == 0;

	return (held_long_enough && is_autowalk_frame);
}

STATIC bool	should_player_shift(keys_t key, t_data *data)
{
	const bool		holding_key = mlx_is_key_down(data->mlx, key);
	const uint32_t	frames_held = data->held_keys[key];
	const bool		key_wasnt_pressed = frames_held == 0;

	return (holding_key && (key_wasnt_pressed || can_autowalk(frames_held)));
}

STATIC void	shift_player(t_player *player, int32_t x, int32_t y, t_data *data)
{
	sl_shift_tile_pos(&player->entity->tile, x, y, data);
}

void	sl_try_move_players(t_data *data)
{
	const int32_t	pixels_per_tile = (int32_t)data->texture.pixels_per_tile;
	t_player		*player;

	while (sl_iterate_player_count(data) != FINISHED)
	{
		player = &data->players[data->t.player_index];
		if (should_player_shift(player->controls.up_key, data))
			shift_player(player, 0, -pixels_per_tile, data);
		if (should_player_shift(player->controls.down_key, data))
			shift_player(player, 0, pixels_per_tile, data);
		if (should_player_shift(player->controls.left_key, data))
			shift_player(player, -pixels_per_tile, 0, data);
		if (should_player_shift(player->controls.right_key, data))
			shift_player(player, pixels_per_tile, 0, data);
	}
}

////////////////////////////////////////////////////////////////////////////////
