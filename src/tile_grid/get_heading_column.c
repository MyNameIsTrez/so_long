/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_heading_column.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 13:28:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 16:53:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_i32	sl_get_heading_column(t_heading heading, t_tile *tile, t_data *data)
{
	t_i32	column;

	column = (t_i32)sl_get_tile_column(tile, data);
	if (heading == HEADING_LEFT)
		return (column - 1);
	if (heading == HEADING_RIGHT)
		return (column + 1);
	return (column);
}

////////////////////////////////////////////////////////////////////////////////
