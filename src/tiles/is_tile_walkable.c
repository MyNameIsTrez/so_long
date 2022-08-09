/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_tile_walkable.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:14:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 16:17:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	is_tile_walkable(size_t column, size_t row, t_data *data)
{
	t_u8	tile_character;

	data->it.column = column;
	data->it.row = row;
	tile_character = sl_get_tile_grid_character(data);
	return (ft_chr_in_str(tile_character, WALKABLE_CHARACTERS));
}

////////////////////////////////////////////////////////////////////////////////
