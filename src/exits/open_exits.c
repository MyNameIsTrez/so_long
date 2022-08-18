/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_exits.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 15:13:01 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/18 15:16:13 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_open_exits(t_data *data)
{
	t_iterator	char_grid_indices_it;

	ft_init_it(&char_grid_indices_it);
	while (sl_iterate_char_grid_indices(&char_grid_indices_it, data) != FINISHED)
		if (sl_get_char_grid_character(data) == MAP_EXIT_CHARACTER)
			sl_change_frame(&data->tile_grid.cells[data->it.char_grid_index], 1);
}

////////////////////////////////////////////////////////////////////////////////
