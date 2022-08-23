/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_try_move.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:30:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 12:09:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_TRY_MOVE_H
# define SL_PRIVATE_TRY_MOVE_H

////////////////////////////////////////////////////////////////////////////////

bool	is_walkable(t_player *player, t_heading heading, t_data *data);
bool	trying_to_move(t_player *player, t_heading heading, t_data *data);
void	update_death_state(t_player *player, t_heading heading, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
