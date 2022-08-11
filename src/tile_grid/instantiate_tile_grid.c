/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile_grid.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 18:02:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 18:31:53 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/instantiate_tile_grid/sl_private_instantiate_tile_grid.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_tile_grid(t_data *data)
{
	t_iterator	it;

	data->tile_grid.cells = ft_vector_new(sizeof(t_tile));
	if (data->tile_grid.cells == NULL)
		return (ERROR);
	ft_init_it(&it);
	while (sl_iterate_char_grid_indices(&it, data) != FINISHED)
		if (instantiate_tile(data) != OK)
			return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
