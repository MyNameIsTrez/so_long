/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_grab_collectible.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 16:11:59 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/17 17:50:02 by sbos          ########   odam.nl         */
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
	t_iterator	char_grid_indices_it;

	ft_init_it(&collectible_it);
	ft_init_it(&char_grid_indices_it);
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
					while (sl_iterate_char_grid_indices(&char_grid_indices_it, data) != FINISHED)
						if (sl_get_char_grid_character(data) == MAP_EXIT_CHARACTER)
							sl_change_frame(&data->tile_grid.cells[data->it.char_grid_index], 1);
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
