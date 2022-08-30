/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 15:53:15 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/30 15:53:15 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sl_private_check_valid_player_path.h"
#include "../sl_private_path_struct.h"

////////////////////////////////////////////////////////////////////////////////

t_status	floodfill(t_path *path, bool *visited, t_data *data)
{
	t_u8	character;

	while (ft_vector_get_size(path->visit_stack) > 0)
	{
		path->current = *(t_tile **)ft_vector_back(path->visit_stack);
		ft_vector_pop_back(&path->visit_stack);
		character = data->char_grid.cells[path->current->index];
		if (character == MAP_EXIT_CHARACTER)
			path->exit_seen = true;
		if (character == COLLECTIBLE_CHARACTER)
			path->collectibles_seen++;
		if (add_unvisited_neighbors(path, visited, data) != OK)
			return (ERROR);
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
