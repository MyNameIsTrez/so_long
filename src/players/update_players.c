/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_players.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 15:45:32 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/22 17:55:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/update_players/sl_private_update_players.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_players(t_data *data)
{
	t_iterator	it;
	t_player	*player;

	ft_init_it(&it);
	while (sl_iterate_players(&it, data) != FINISHED)
	{
		player = data->it.player;
		if (!player->dead)
			update_player(player, data);
	}
}

////////////////////////////////////////////////////////////////////////////////
