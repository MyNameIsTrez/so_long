/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_utils.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 12:13:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/01 18:23:18 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef A_UTILS_H
# define A_UTILS_H

////////////////////////////////////////////////////////////////////////////////

# include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_data		t_data;
typedef struct s_tile		t_tile;
typedef struct s_tile_kind	t_tile_kind;

////////////////////////////////////////////////////////////////////////////////

bool			sl_is_entity(uint32_t column_index, uint32_t row_index,
					t_data *data);
t_status		sl_initialize_instance_for_frames(t_tile *tile,
					uint32_t column_index, uint32_t row_index, t_data *data);
void			sl_shift_tile_pos(t_tile *tile, int32_t x, int32_t y);
void			sl_set_tile_pos(t_tile *tile, int32_t x, int32_t y);
t_status		sl_fill_tile_data(t_tile_kind *tile_kind, t_tile *tile);
mlx_instance_t	*sl_get_instance(t_tile *tile, uint32_t frame_index);
mlx_image_t		*sl_get_frame(t_tile_kind *tile_kind,
					uint32_t frame_instance_index);
unsigned char	sl_get_grid_character(uint32_t column_index, uint32_t row_index,
					t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
