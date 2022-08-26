/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_collect_collectible.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 16:11:59 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 12:20:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "try_collect_collectible/sl_private_try_collect_collectible.h"

////////////////////////////////////////////////////////////////////////////////

void	try_collect_collectible(t_player *player, t_data *data)
{
	t_iterator	collectible_it;

	ft_init_it(&collectible_it);
	while (sl_iterate_collectibles(&collectible_it, data) != FINISHED)
		if (sl_entities_have_same_position(player->entity,
				data->it.collectible->entity))
			if (!data->it.collectible->collected)
				sl_collect_collectible(data->it.collectible, data);
}

////////////////////////////////////////////////////////////////////////////////
