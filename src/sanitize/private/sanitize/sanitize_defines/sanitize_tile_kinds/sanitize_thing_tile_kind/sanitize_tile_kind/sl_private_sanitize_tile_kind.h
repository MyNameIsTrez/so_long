/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_sanitize_tile_kind.h                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 16:32:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 11:19:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_SANITIZE_TILE_KIND_H
# define SL_PRIVATE_SANITIZE_TILE_KIND_H

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_max_color(
				t_tile_kind_color tile_kind_data_color, t_data *data);
t_status	sanitize_min_color(
				t_tile_kind_color tile_kind_data_color, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
