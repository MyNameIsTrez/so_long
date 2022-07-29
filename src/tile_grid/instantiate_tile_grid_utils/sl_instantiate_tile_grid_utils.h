/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_instantiate_tile_grid_utils.h                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:51:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:51:33 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_INSTANTIATE_TILE_GRID_UTILS_H
# define SL_INSTANTIATE_TILE_GRID_UTILS_H

////////////////////////////////////////////////////////////////////////////////

t_tile_kind	*get_tile_grid_tile_kind(t_data *data);
t_status	instantiate_tile(t_data *data);
t_status	malloc_rows(t_data *data);
t_status	malloc_tile_grid_cells(t_data *data);
t_status	try_instantiate_tile(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////