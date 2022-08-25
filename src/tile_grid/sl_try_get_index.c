/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_try_get_index.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 19:00:43 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 19:01:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	sl_try_get_index(size_t *index, t_heading heading, t_tile *tile,
			t_data *data)
{
	t_i32	column;
	t_i32	row;

	column = sl_get_heading_column(heading, tile, data);
	row = sl_get_heading_row(heading, tile, data);
	if (sl_out_of_bounds(column, row, data))
		return (false);
	*index = sl_get_index((size_t)column, (size_t)row, data);
	return (true);
}

////////////////////////////////////////////////////////////////////////////////
