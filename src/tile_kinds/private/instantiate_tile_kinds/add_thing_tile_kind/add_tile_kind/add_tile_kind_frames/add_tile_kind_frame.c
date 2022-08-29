/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_tile_kind_frame.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/29 10:18:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/29 10:18:45 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_tile_kind_frame(t_tile_kind *tile_kind, t_u32 xy[2],
				t_u32 wh[2], t_data *data)
{
	mlx_image_t	*frame;
	size_t		channel_count;
	t_u8		*original_frame_pixels;

	frame = mlx_texture_area_to_image(data->mlx, data->texture.data, xy, wh);
	if (frame == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	if (ft_vector_push(&tile_kind->frames, &frame) != OK)
		return (ERROR);
	channel_count = frame->width * frame->height * 4;
	original_frame_pixels = ft_vector_new_reserved(sizeof(t_u8), channel_count);
	if (original_frame_pixels == NULL)
		return (ERROR);
	ft_memcpy(original_frame_pixels, frame->pixels,
		channel_count * sizeof(t_u8));
	if (ft_vector_push(&tile_kind->original_frames_pixels,
			&original_frame_pixels) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
