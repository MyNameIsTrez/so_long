/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_count.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:56:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 12:59:30 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frame_count(uint32_t frame_count,
			t_data *data, bool reset)
{
	static uint32_t	frame_index;

	if (reset)
	{
		frame_index = 0;
		data->it.frame_index = 0;
		return (RESET);
	}
	while (frame_index < frame_count)
	{
		data->it.frame_index = frame_index;
		frame_index++;
		return (LOOPED);
	}
	sl_reset_iterate_frame_count(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_count(uint32_t frame_count, t_data *data)
{
	return (resettable_iterate_frame_count(frame_count, data, false));
}

void	sl_reset_iterate_frame_count(t_data *data)
{
	resettable_iterate_frame_count(0, data, true);
}

////////////////////////////////////////////////////////////////////////////////
