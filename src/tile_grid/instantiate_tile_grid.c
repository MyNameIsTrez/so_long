/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile_grid.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 18:02:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 12:31:56 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/instantiate_tile_grid/sl_private_instantiate_tile_grid.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_tile_grid(t_data *data)
{
	t_it_char_grid	it;

	if (malloc_tile_grid_cells(data) != OK)
		return (ERROR);
	sl_init_it_char_grid(&it);
	while (sl_iterate_char_grid(&it, data) != FINISHED)
		if (instantiate_tile(data) != OK)
			return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
