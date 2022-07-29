/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_try_move_players_utils.h                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:30:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:40:37 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TRY_MOVE_PLAYERS_UTILS_H
# define SL_TRY_MOVE_PLAYERS_UTILS_H

////////////////////////////////////////////////////////////////////////////////

# define UP_MOVEMENT_KEY_INDEX 0
# define DOWN_MOVEMENT_KEY_INDEX 1
# define LEFT_MOVEMENT_KEY_INDEX 2
# define RIGHT_MOVEMENT_KEY_INDEX 3

////////////////////////////////////////////////////////////////////////////////

bool	can_autowalk(t_player *player, t_data *data);
bool	can_player_shift(t_player *player, size_t movement_key_index,
			t_data *data);
t_i32	get_key_column_offset(keys_t key, keys_t movement_keys[4]);
t_i32	get_key_row_offset(keys_t key, keys_t movement_keys[4]);
bool	is_entity_walkable(size_t column, size_t row, t_data *data);
bool	is_tile_walkable(size_t column, size_t row, t_data *data);
bool	is_walkable(t_player *player, keys_t key, t_data *data);
void	shift_player(t_player *player, t_i32 x, t_i32 y, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
