/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb_channel_indices.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 14:31:40 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 19:06:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#define CHANNEL_COUNT 3

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_rgb_channel_indices(t_iterator *it, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_count_iterator(CHANNEL_COUNT);
	if (ft_iterate(it) != FINISHED)
	{
		data->it.rgb_channel_index = (size_t)it->current;
		return (LOOPED);
	}
	data->it.rgb_channel_index = (size_t)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
