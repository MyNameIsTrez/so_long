/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frames.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 11:44:54 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/28 11:13:54 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frames(t_tile_kind *tile_kind,
								t_data *data, bool reset)
{
	if (reset)
	{
		data->it.frame = NULL;
		return (RESET);
	}
	while (sl_iterate_frame_count(tile_kind->frame_count, data) != FINISHED)
	{
		data->it.frame = tile_kind->frames[data->it.frame_index];
		return (LOOPED);
	}
	sl_reset_iterate_frames(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frames(t_tile_kind *tile_kind, t_data *data)
{
	return (resettable_iterate_frames(tile_kind, data, false));
}

void	sl_reset_iterate_frames(t_data *data)
{
	resettable_iterate_frames(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
