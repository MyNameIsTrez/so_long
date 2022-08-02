/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_instantiate_tile_kinds_utils.h                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:59:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/02 16:27:03 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_INSTANTIATE_TILE_KINDS_UTILS_H
# define SL_INSTANTIATE_TILE_KINDS_UTILS_H

////////////////////////////////////////////////////////////////////////////////

t_status	add_tile_kind_frames(t_tile_kind *tile_kind, size_t frame_count,
				size_t texture_row, t_data *data);
t_status	add_tile_kind(t_tile_kind_data tk_data, t_data *data);
t_status	instantiate_tile_kind_color(t_tile_kind_color *color,
				t_tile_kind_data_color tk_data_color, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
