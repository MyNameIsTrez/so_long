/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frames_pixel_indices.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 16:01:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/10 16:41:15 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frames_pixel_indices(
						t_it_frames_pixel_indices *it, t_tile_kind *tile_kind,
						t_data *data)
{
	if (!it->frames_it.initialized)
		sl_iterate_frames(&it->frames_it, tile_kind, data);
	while (true)
	{
		if (sl_iterate_frame_pixel_indices(&it->frame_pixel_indices_it,
				data->it.frame, data) != FINISHED)
			return (LOOPED);
		if (sl_iterate_frames(&it->frames_it, tile_kind, data) == FINISHED)
			break ;
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_init_it_frames_pixel_indices(t_it_frames_pixel_indices *it)
{
	ft_bzero(it, sizeof(t_it_frames_pixel_indices));
}

////////////////////////////////////////////////////////////////////////////////
