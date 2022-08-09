/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_grab_collectible.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 16:11:59 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 17:16:24 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	sl_entities_have_same_position(t_entity *entity_1, t_entity *entity_2)
{
	t_tile	*tile_1;
	t_tile	*tile_2;

	tile_1 = &entity_1->tile;
	tile_2 = &entity_2->tile;
	return (tile_1->column == tile_2->column && tile_1->row == tile_2->row);
}

void	try_grab_collectible(t_player *player, t_data *data)
{
	t_iterator	it;

	ft_init_it(&it);
	while (sl_iterate_collectibles(&it, data) != FINISHED)
	{
		if (sl_entities_have_same_position(player->entity, data->it.collectible->entity))
		{
			if (!data->it.collectible->collected)
			{
				data->it.collectible->collected = true;
				sl_get_frame_instance(&data->it.collectible->entity->tile, data->it.collectible->entity->tile.frame_index)->enabled = false;
				data->it.collectible->entity->enabled = false;
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
