/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc_rows.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:49:49 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:49:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	malloc_rows(t_data *data)
{
	t_tile	**cells;
	size_t	row_index;

	cells = data->tile_grid.cells;
	row_index = data->it.row_index;
	cells[row_index] = ft_malloc((size_t)data->char_grid.width, sizeof(t_tile));
	if (cells[row_index] == NULL)
		return (ft_set_error(FT_ERROR_MALLOC));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
