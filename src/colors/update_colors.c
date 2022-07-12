/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_colors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/12 13:48:34 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	update_wall_colors(mlx_image_t *frame, t_data *data)
{
	while (sl_iterate_frame_pixels(frame, data) != FINISHED)
		frame->pixels[(data->t.frame_pixels.x + data->t.frame_pixels.y * frame->width) * 4]++;
}

////////////////////////////////////////////////////////////////////////////////

void	sl_update_colors(t_data *data)
{
	update_wall_colors(data->tile_kinds[WALL_CHARACTER].frames[0], data);
}

////////////////////////////////////////////////////////////////////////////////
