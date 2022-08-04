/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile_grid.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 18:02:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/04 13:34:34 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "instantiate_tile_grid_utils/sl_instantiate_tile_grid_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_tile_grid(t_data *data)
{
	if (malloc_tile_grid_cells(data) != OK)
		return (ERROR);
	while (sl_iterate_char_grid(data) != FINISHED)
		if (instantiate_tile(data) != OK)
			return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
