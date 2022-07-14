/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_count.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 15:17:20 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 11:58:05 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_player_count(t_data *data,
			bool reset)
{
	static uint32_t	player_index;

	if (reset)
	{
		player_index = 0;
		data->it.player_index = 0;
		return (RESET);
	}
	while (player_index < data->player_count)
	{
		data->it.player_index = player_index;
		player_index++;
		return (LOOPED);
	}
	sl_reset_iterate_player_count(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_player_count(t_data *data)
{
	return (resettable_iterate_player_count(data, false));
}

void	sl_reset_iterate_player_count(t_data *data)
{
	resettable_iterate_player_count(data, true);
}

////////////////////////////////////////////////////////////////////////////////
