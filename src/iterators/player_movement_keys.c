/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement_keys.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 12:08:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 21:04:22 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_player_movement_keys(
								t_player *player, t_data *data, bool reset)
{
	static t_iterator	it;
	keys_t				*movement_keys;

	if (reset)
	{
		it.initialized = false;
		data->it.player_movement_key = 0;
		return (RESET);
	}
	movement_keys = player->controls.movement_keys;
	if (!it.initialized)
		it = ft_get_array_iterator(movement_keys, 4, sizeof(keys_t));
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.player_movement_key = *(keys_t *)it.current;
		return (LOOPED);
	}
	sl_reset_iterate_player_movement_keys(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_player_movement_keys(t_player *player,
			t_data *data)
{
	return (resettable_iterate_player_movement_keys(player, data, false));
}

void	sl_reset_iterate_player_movement_keys(t_data *data)
{
	resettable_iterate_player_movement_keys(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
