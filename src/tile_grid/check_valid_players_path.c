/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_valid_players_path.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 20:52:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 20:52:18 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/check_valid_players_path/\
sl_private_check_valid_players_path.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_check_valid_players_path(t_data *data)
{
	size_t		char_grid_size;
	bool		*visited;
	t_iterator	it;

	char_grid_size = data->char_grid.width * data->char_grid.height;
	visited = ft_vector_new_reserved(sizeof(bool), char_grid_size);
	if (visited == NULL)
		return (ERROR);
	ft_init_it(&it);
	while (sl_iterate_players(&it, data) != FINISHED)
		if (check_valid_player_path(data->it.player, visited, data) != OK)
			return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
