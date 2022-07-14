/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_tiles.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 13:22:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 11:11:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TILES_H
# define SL_TILES_H

////////////////////////////////////////////////////////////////////////////////

bool		sl_out_of_bounds(int32_t column, int32_t row, t_data *data);
bool		sl_is_entity(t_data *data);
t_status	sl_instantiate_tile_frames(t_tile *tile, t_data *data);
void		sl_shift_tile_pos(t_tile *tile, int32_t columns, int32_t rows,
				t_data *data);
t_status	sl_fill_tile_data(t_tile *tile, t_tile_kind *tile_kind,
				t_data *data);
t_tile		*sl_get_tile(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
