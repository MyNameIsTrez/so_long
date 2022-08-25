/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_tile_grid.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:43:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 19:02:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TILE_GRID_H
# define SL_TILE_GRID_H

////////////////////////////////////////////////////////////////////////////////

t_i32		sl_get_heading_column(t_heading heading, t_tile *tile,
				t_data *data);
size_t		sl_get_heading_index(t_heading heading, t_tile *tile, t_data *data);
t_i32		sl_get_heading_row(t_heading heading, t_tile *tile, t_data *data);
t_u8		sl_get_tile_grid_character(size_t index, t_data *data);
t_status	sl_instantiate_tile_grid(t_data *data);
bool		sl_try_get_index(size_t *index, t_heading heading, t_tile *tile,
				t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
