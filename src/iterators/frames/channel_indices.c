/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   channel_indices.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 14:31:40 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/12 14:31:42 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_channel_indices(t_data *data, bool reset)
{
	static uint32_t	channel_index;

	if (reset)
	{
		channel_index = 0;
		data->t.channel_index = 0;
		return (RESET);
	}
	while (channel_index < 4)
	{
		data->t.channel_index = channel_index;
		channel_index++;
		return (LOOPED);
	}
	sl_reset_iterate_channel_indices(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_channel_indices(t_data *data)
{
	return (resettable_iterate_channel_indices(data, false));
}

void	sl_reset_iterate_channel_indices(t_data *data)
{
	resettable_iterate_channel_indices(data, true);
}

////////////////////////////////////////////////////////////////////////////////