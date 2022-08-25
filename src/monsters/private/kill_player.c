/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:42:47 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 18:35:37 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	kill_player(t_heading heading, t_tile *monster_tile, t_data *data)
{
	size_t	index;

	index = sl_get_index(
		(size_t)sl_get_heading_column(heading, monster_tile, data),
		(size_t)sl_get_heading_row(heading, monster_tile, data), data);


	t_iterator	it;
	t_player	*player;

	ft_init_it(&it);
	while (sl_iterate_players(&it, data) != FINISHED)
	{
		player = data->it.player;
		if (player->entity->tile.index == index)
		{
			player->entity->tile.index = 0;
			player->dying = true;
			return ;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
