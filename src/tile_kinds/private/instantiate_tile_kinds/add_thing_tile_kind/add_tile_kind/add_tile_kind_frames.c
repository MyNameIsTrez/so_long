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

t_status	add_tile_kind_frames(t_tile_kind *tile_kind, size_t frame_count,
				size_t texture_row, t_data *data)
{
	t_iterator	it;
	size_t		pixels_per_tile;
	t_u32		wh[2];
	t_u32		xy[2];
	mlx_image_t	*frame;
	t_u8		*original_frames_pixels;

	ft_init_it(&it);
	pixels_per_tile = data->texture.pixels_per_tile;
	wh[0] = (t_u32)pixels_per_tile;
	wh[1] = (t_u32)pixels_per_tile;
	while (sl_iterate_frame_count(&it, frame_count, data) != FINISHED)
	{
		xy[0] = (t_u32)(pixels_per_tile * data->it.frame_index);
		xy[1] = (t_u32)(pixels_per_tile * texture_row);
		frame = mlx_texture_area_to_image(data->mlx, data->texture.data, xy,
				wh);
		if (frame == NULL)
			return (sl_set_error(SL_ERROR_MLX42));
		if (ft_vector_push(&tile_kind->frames, &frame) != OK)
			return (ERROR);
		original_frames_pixels = ft_vector_new_reserved(sizeof(t_u8), frame->width * frame->height * 4);
		if (original_frames_pixels == NULL)
			return (ERROR);
		ft_memcpy(original_frames_pixels, frame->pixels, frame->width * frame->height * 4 * sizeof(t_u8));
		if (ft_vector_push(&tile_kind->original_frames_pixels, &original_frames_pixels) != OK)
			return (ERROR);
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
