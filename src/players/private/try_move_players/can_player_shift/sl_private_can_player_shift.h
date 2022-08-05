/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_can_player_shift.h                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 16:14:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 20:34:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_CAN_PLAYER_SHIFT_H
# define SL_PRIVATE_CAN_PLAYER_SHIFT_H

////////////////////////////////////////////////////////////////////////////////

bool	can_autowalk(t_player *player, t_data *data);
bool	is_walkable(t_player *player, t_heading heading, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
