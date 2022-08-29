/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_valid_player_path.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/10 13:48:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 19:02:05 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "check_valid_player_path/sl_private_check_valid_player_path.h"

////////////////////////////////////////////////////////////////////////////////

t_status	check_valid_player_path(t_player *player, bool *visited,
				t_data *data)
{
	t_tile	**visit_stack;
	t_tile	*current;

	ft_bzero(visited, ft_vector_get_capacity(visited) * sizeof(bool));
	visit_stack = ft_vector_new(sizeof(t_tile *));
	if (visit_stack == NULL)
		return (ERROR);
	current = &player->entity->tile;
	visited[current->index] = true;
	if (add_unvisited_neighbors(current, &visit_stack, visited, data) != OK)
		return (ERROR);
	while (ft_vector_get_size(visit_stack) > 0)
	{
		current = *(t_tile **)ft_vector_back(visit_stack);
		ft_vector_pop_back(&visit_stack);
		if (current->tile_kind->character == MAP_EXIT_CHARACTER)
			return (OK);
		if (add_unvisited_neighbors(current, &visit_stack, visited, data) != OK)
			return (ERROR);
	}
	return (sl_set_error(SL_ERROR_NO_PATH));
}

////////////////////////////////////////////////////////////////////////////////
