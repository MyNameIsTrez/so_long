/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   channel_indices.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 14:31:40 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/15 16:37:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_rgb_channel_indices(t_data *data,
			bool reset)
{
	static t_i32	rgb_channel_index;

	if (reset)
	{
		rgb_channel_index = 0;
		data->it.rgb_channel_index = 0;
		return (RESET);
	}
	while (rgb_channel_index < 3)
	{
		data->it.rgb_channel_index = rgb_channel_index;
		rgb_channel_index++;
		return (LOOPED);
	}
	sl_reset_iterate_rgb_channel_indices(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_rgb_channel_indices(t_data *data)
{
	return (resettable_iterate_rgb_channel_indices(data, false));
}

void	sl_reset_iterate_rgb_channel_indices(t_data *data)
{
	resettable_iterate_rgb_channel_indices(data, true);
}

////////////////////////////////////////////////////////////////////////////////
