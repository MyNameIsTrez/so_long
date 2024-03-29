/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_tile_kind_frames.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:00:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 17:28:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_tile_kind_frames/sl_private_add_tile_kind_frames.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_tile_kind_frames(t_tile_kind *tile_kind, size_t frame_count,
				size_t texture_row, t_data *data)
{
	t_iterator	it;
	size_t		pixels_per_tile;
	t_u32		wh[2];
	t_u32		xy[2];

	ft_init_it(&it);
	pixels_per_tile = data->texture.pixels_per_tile;
	wh[0] = (t_u32)pixels_per_tile;
	wh[1] = (t_u32)pixels_per_tile;
	while (sl_iterate_frame_count(&it, frame_count, data) != FINISHED)
	{
		xy[0] = (t_u32)(pixels_per_tile * data->it.frame_index);
		xy[1] = (t_u32)(pixels_per_tile * texture_row);
		if (add_tile_kind_frame(tile_kind, xy, wh, data) != OK)
			return (ERROR);
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
