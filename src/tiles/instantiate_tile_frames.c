/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile_frames.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:37:17 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 14:14:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/instantiate_tile_frames/sl_private_instantiate_tile_frames.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_tile_frames(t_tile *tile, t_data *data)
{
	t_iterator	it;

	ft_init_it(&it);
	while (sl_iterate_frame_count(&it, tile->tile_kind->frame_count,
			data) != FINISHED)
		if (sl_instantiate_tile_frame(tile, data->it.frame_index, data) != OK)
			return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
