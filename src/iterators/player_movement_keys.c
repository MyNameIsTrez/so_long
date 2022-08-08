/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement_keys.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 12:08:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 16:20:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_player_movement_keys(t_iterator *it,
						t_player *player, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_array_iterator(player->controls.movement_keys, 4,
				sizeof(keys_t));
	while (ft_iterate(it) != FINISHED)
	{
		data->it.player_movement_key = *(keys_t *)it->current;
		return (LOOPED);
	}
	data->it.player_movement_key = *(keys_t *)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
