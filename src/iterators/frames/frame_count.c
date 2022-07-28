/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_count.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:56:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/28 11:04:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frame_count(t_i32 frame_count,
								t_data *data, bool reset)
{
	static t_iterator	it;

	if (reset)
	{
		it.initialized = false;
		data->it.frame_index = 0;
		return (RESET);
	}
	if (!it.initialized)
		it = ft_get_range_start_0_iterator(frame_count);
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.frame_index = (t_i32)it.current;
		return (LOOPED);
	}
	sl_reset_iterate_frame_count(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_count(t_i32 frame_count, t_data *data)
{
	return (resettable_iterate_frame_count(frame_count, data, false));
}

void	sl_reset_iterate_frame_count(t_data *data)
{
	resettable_iterate_frame_count(0, data, true);
}

////////////////////////////////////////////////////////////////////////////////
