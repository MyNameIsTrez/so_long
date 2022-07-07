/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_count.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 15:17:20 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/07 15:21:03 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_player_count(t_data *data)
{
	while (data->t.it.player_index < data->player_count)
	{
		data->t.player_index = data->t.it.player_index;
		data->t.it.player_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_reset_iterate_player_count(t_data *data)
{
	data->t.it.player_index = 0;
}

////////////////////////////////////////////////////////////////////////////////
