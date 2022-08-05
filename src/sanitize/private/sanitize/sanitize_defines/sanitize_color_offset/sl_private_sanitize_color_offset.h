/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_sanitize_color_offset.h                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:58:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 15:24:23 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_SANITIZE_COLOR_OFFSET_H
# define SL_PRIVATE_SANITIZE_COLOR_OFFSET_H

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_max_color_offset(
				t_tile_kind_data_color tile_kind_data_color, t_data *data);
t_status	sanitize_min_color_offset(
				t_tile_kind_data_color tile_kind_data_color, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
