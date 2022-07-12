/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_colors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/12 14:09:10 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC uint32_t	get_index(mlx_image_t *frame, t_data *data)
{
	const t_frame_pixels	*frame_pixels = &data->t.frame_pixels;
	const uint32_t			x = frame_pixels->x;
	const uint32_t			y = frame_pixels->y;
	const uint32_t			width = frame->width;

	return ((x + y * width) * 4);
}

STATIC void	update_wall_colors(mlx_image_t *frame, t_data *data)
{
	while (sl_iterate_frame_pixels(frame, data) != FINISHED)
		frame->pixels[get_index(frame, data)]++;
}

////////////////////////////////////////////////////////////////////////////////

void	sl_update_colors(t_data *data)
{
	update_wall_colors(data->tile_kinds[WALL_CHARACTER].frames[0], data);
}

////////////////////////////////////////////////////////////////////////////////
