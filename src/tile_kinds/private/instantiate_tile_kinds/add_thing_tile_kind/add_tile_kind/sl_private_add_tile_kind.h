/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_add_tile_kind.h                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:04:04 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 17:55:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_ADD_TILE_KIND_H
# define SL_PRIVATE_ADD_TILE_KIND_H

////////////////////////////////////////////////////////////////////////////////

t_status	add_tile_kind_frames(t_tile_kind *tile_kind, size_t frame_count,
				size_t texture_row, t_data *data);
t_status	instantiate_tile_kind_color(t_tile_kind_color *color,
				t_tile_kind_data_color tk_data_color, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
