/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_tiles.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 13:22:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/28 14:24:21 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TILES_H
# define SL_TILES_H

////////////////////////////////////////////////////////////////////////////////

bool		sl_out_of_bounds(t_i32 column, t_i32 row, t_data *data);
t_status	sl_instantiate_tile_frames(t_tile *tile, t_data *data);
void		sl_shift_tile_pos(t_tile *tile, t_i32 columns, t_i32 rows,
				t_data *data);
t_status	sl_fill_tile_data(t_tile *tile, t_tile_kind *tile_kind,
				t_data *data);
t_tile		*sl_get_tile(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
