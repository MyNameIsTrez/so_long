/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_instantiate_tile_kinds.h                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:59:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 16:29:21 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_INSTANTIATE_TILE_KINDS_H
# define SL_PRIVATE_INSTANTIATE_TILE_KINDS_H

////////////////////////////////////////////////////////////////////////////////

t_status	add_collectible_tile_kind(t_data *data);
t_status	add_empty_space_tile_kind(t_data *data);
t_status	add_exit_lock_tile_kind(t_data *data);
t_status	add_map_exit_tile_kind(t_data *data);
t_status	add_monster_tile_kind(t_data *data);
t_status	add_player_1_tile_kind(t_data *data);
t_status	add_player_2_tile_kind(t_data *data);
t_status	add_wall_tile_kind(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
