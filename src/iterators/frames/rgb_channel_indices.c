/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb_channel_indices.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 14:31:40 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#define CHANNEL_COUNT 3

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_rgb_channel_indices(t_data *data,
								bool reset)
{
	static t_iterator	it;

	if (reset)
	{
		it.initialized = false;
		data->it.rgb_channel_index = 0;
		return (RESET);
	}
	if (!it.initialized)
		it = ft_get_count_iterator(CHANNEL_COUNT);
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.rgb_channel_index = (size_t)it.current;
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
