/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shift_tile_pos_to_heading.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:37:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 16:42:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_shift_tile_pos_to_heading(t_tile *tile, t_heading heading,
			t_data *data)
{
	size_t	column;
	size_t	row;

	column = (size_t)sl_get_heading_column(heading, tile, data);
	row = (size_t)sl_get_heading_row(heading, tile, data);
	sl_set_tile_pos(tile, sl_get_index(column, row, data), data);
}

////////////////////////////////////////////////////////////////////////////////
