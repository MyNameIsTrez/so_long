/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc_tile_grid_cells.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:49:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 17:15:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	malloc_tile_grid_cells(t_data *data)
{
	t_tile		**cells;

	cells = ft_vector_new(sizeof(t_tile *));
	if (cells == NULL)
		return (ERROR);
	data->tile_grid.cells = cells;
	while (sl_iterate_char_grid_height(data) != FINISHED)
		if (ft_vector_push_new_vector(&data->tile_grid.cells,
				sizeof(t_tile)) != OK)
			return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
