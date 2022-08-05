/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_sanitize_tile_kinds.h                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:59:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 15:24:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_SANITIZE_TILE_KINDS_H
# define SL_PRIVATE_SANITIZE_TILE_KINDS_H

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_collectible(t_data *data);
t_status	sanitize_empty_space(t_data *data);
t_status	sanitize_map_exit(t_data *data);
t_status	sanitize_player_1(t_data *data);
t_status	sanitize_player_2(t_data *data);
t_status	sanitize_wall(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
