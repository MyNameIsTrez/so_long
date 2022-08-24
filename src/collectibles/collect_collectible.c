/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collect_collectible.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 12:16:52 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 12:35:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_collect_collectible(t_collectible *collectible, t_data *data)
{
	collectible->collected = true;
	sl_get_frame_instance(&collectible->entity->tile, collectible->entity->tile.frame_index)->enabled = false;
	collectible->entity->enabled = false;
	data->collected_count++;
	if (data->collected_count == ft_vector_get_size(data->collectibles))
		data->can_exit = true;
}

////////////////////////////////////////////////////////////////////////////////
