/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_walk_into_exit.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 17:55:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/18 15:19:58 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	try_walk_into_exit(t_player *player, t_data *data)
{
	size_t		player_index;

	player_index = player->entity->tile.index;
	if (data->can_exit && data->char_grid.cells[player_index] == MAP_EXIT_CHARACTER)
		data->finished_level = true;
}

////////////////////////////////////////////////////////////////////////////////
