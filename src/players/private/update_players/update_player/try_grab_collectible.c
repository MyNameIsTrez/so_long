/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_grab_collectible.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 16:11:59 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/18 15:19:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "try_grab_collectible/sl_private_try_grab_collectible.h"

////////////////////////////////////////////////////////////////////////////////

void	try_grab_collectible(t_player *player, t_data *data)
{
	t_iterator	collectible_it;

	ft_init_it(&collectible_it);
	while (sl_iterate_collectibles(&collectible_it, data) != FINISHED)
	{
		if (sl_entities_have_same_position(player->entity, data->it.collectible->entity))
		{
			if (!data->it.collectible->collected)
			{
				data->it.collectible->collected = true;
				sl_get_frame_instance(&data->it.collectible->entity->tile, data->it.collectible->entity->tile.frame_index)->enabled = false;
				data->it.collectible->entity->enabled = false;
				data->collected_count++;
				if (data->collected_count == ft_vector_get_size(data->collectibles))
				{
					data->can_exit = true;
					sl_open_exits(data);
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
