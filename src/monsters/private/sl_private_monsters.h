/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_monsters.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:29:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 17:47:33 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_MONSTERS_H
# define SL_PRIVATE_MONSTERS_H

////////////////////////////////////////////////////////////////////////////////

bool	is_player_in_way(t_heading heading, t_tile *monster_tile, t_data *data);
void	kill_player(t_heading heading, t_tile *monster_tile, t_data *data);
void	set_monster_heading(t_monster *monster, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
