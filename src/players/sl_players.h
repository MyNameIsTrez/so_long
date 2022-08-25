/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_players.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 10:37:54 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 18:46:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PLAYERS_H
# define SL_PLAYERS_H

////////////////////////////////////////////////////////////////////////////////

t_status	sl_initialize_players(t_data *data);
void		sl_start_player_dying(t_player *player);
void		sl_update_players(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
