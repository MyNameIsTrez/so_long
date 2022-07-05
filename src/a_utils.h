/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_utils.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 12:13:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/05 16:06:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef A_UTILS_H
# define A_UTILS_H

////////////////////////////////////////////////////////////////////////////////

# include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool			sl_is_entity(t_data *data);
t_status		sl_instance_tile_frames(t_tile *tile, t_data *data);
void			sl_shift_tile_pos(t_tile *tile, int32_t x, int32_t y);
void			sl_set_tile_pos(t_tile *tile, int32_t x, int32_t y);
t_status		sl_fill_tile_data(t_tile_kind *tile_kind, t_tile *tile);
mlx_instance_t	*sl_get_instance(t_tile *tile, uint32_t frame_index);
mlx_image_t		*sl_get_frame(t_tile_kind *tile_kind,
					uint32_t frame_instance_index);
unsigned char	sl_get_grid_character(t_data *data);
t_tile			*sl_get_tile(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
