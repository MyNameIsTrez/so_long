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
#include "sl_private_path_struct.h"

////////////////////////////////////////////////////////////////////////////////

t_status	check_valid_player_path(t_player *player, bool *visited,
				t_data *data)
{
	t_path	path;

	ft_bzero(visited, ft_vector_get_capacity(visited) * sizeof(bool));
	path.visit_stack = ft_vector_new(sizeof(t_tile *));
	if (path.visit_stack == NULL)
		return (ERROR);
	path.exit_seen = false;
	path.collectibles_seen = 0;
	path.current = &player->entity->tile;
	visited[path.current->index] = true;
	if (add_unvisited_neighbors(&path, visited, data) != OK)
		return (ERROR);
	if (floodfill(&path, visited, data) != OK)
		return (ERROR);
	if (!path.exit_seen)
		return (sl_set_error(SL_ERROR_NO_PATH));
	if (path.collectibles_seen != ft_vector_get_size(data->collectibles))
		return (sl_set_error(SL_ERROR_UNREACHABLE_COLLECTIBLE));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
