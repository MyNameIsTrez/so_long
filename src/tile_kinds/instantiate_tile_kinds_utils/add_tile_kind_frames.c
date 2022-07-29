/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_tile_kind_frames.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:00:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:00:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_tile_kind_frames(t_tile_kind *tile_kind, size_t frame_count,
				size_t texture_row, t_data *data)
{
	size_t	pixels_per_tile;
	size_t	frame_index;
	t_u32	wh[2];
	t_u32	xy[2];

	pixels_per_tile = data->texture.pixels_per_tile;
	wh[0] = (t_u32)pixels_per_tile;
	wh[1] = (t_u32)pixels_per_tile;
	while (sl_iterate_frame_count(frame_count, data) != FINISHED)
	{
		frame_index = data->it.frame_index;
		xy[0] = (t_u32)(pixels_per_tile * frame_index);
		xy[1] = (t_u32)(pixels_per_tile * texture_row);
		tile_kind->frames[frame_index] = mlx_texture_area_to_image(data->mlx,
				data->texture.data, xy, wh);
		if (tile_kind->frames[frame_index] == NULL)
			return (sl_set_error(SL_ERROR_MLX42));
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
