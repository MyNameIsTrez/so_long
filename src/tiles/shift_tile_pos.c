/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shift_tile_pos.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:37:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 18:46:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_shift_tile_pos(t_tile *tile, t_i32 columns, t_i32 rows, t_data *data)
{
	size_t	column;
	size_t	row;

	column = (size_t)((t_i32)sl_get_tile_column(tile, data) + columns);
	row = (size_t)((t_i32)sl_get_tile_row(tile, data) + rows);
	sl_set_tile_pos(tile, sl_get_index(column, row, data), data);
}

////////////////////////////////////////////////////////////////////////////////
