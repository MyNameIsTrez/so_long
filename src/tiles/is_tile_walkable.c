/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_tile_walkable.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:14:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:40:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	is_tile_walkable(size_t column, size_t row, t_data *data)
{
	t_u8	tile_character;

	data->it.column_index = column;
	data->it.row_index = row;
	tile_character = sl_get_tile_grid_character(data);
	return (ft_chr_in_str(tile_character, WALKABLE_CHARACTERS));
}

////////////////////////////////////////////////////////////////////////////////
