/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_try_move_players.h                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:30:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 16:15:37 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_TRY_MOVE_PLAYERS_H
# define SL_PRIVATE_TRY_MOVE_PLAYERS_H

////////////////////////////////////////////////////////////////////////////////

# define UP_MOVEMENT_KEY_INDEX 0
# define DOWN_MOVEMENT_KEY_INDEX 1
# define LEFT_MOVEMENT_KEY_INDEX 2
# define RIGHT_MOVEMENT_KEY_INDEX 3

////////////////////////////////////////////////////////////////////////////////

bool	can_player_shift(t_player *player, size_t movement_key_index,
			t_data *data);
void	shift_player(t_player *player, t_i32 x, t_i32 y, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
