/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_char_grid_character.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:32:14 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:32:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_u8	sl_get_char_grid_character(t_data *data)
{
	size_t	row_index;
	size_t	column_index;

	row_index = data->it.row_index;
	column_index = data->it.column_index;
	return ((t_u8)data->char_grid.cells[row_index][column_index]);
}

////////////////////////////////////////////////////////////////////////////////
