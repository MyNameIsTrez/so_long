/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_instantiate_tile_kinds_utils_add_tile_ki        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:04:04 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 16:37:45 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_INSTANTIATE_TILE_KINDS_UTILS_ADD_TILE_KIND_H
# define SL_INSTANTIATE_TILE_KINDS_UTILS_ADD_TILE_KIND_H

////////////////////////////////////////////////////////////////////////////////

t_status	add_collectible_tile_kind(t_data *data);
t_status	add_empty_space_tile_kind(t_data *data);
t_status	add_map_exit_tile_kind(t_data *data);
t_status	add_player_1_tile_kind(t_data *data);
t_status	add_player_2_tile_kind(t_data *data);
t_status	add_wall_tile_kind(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
