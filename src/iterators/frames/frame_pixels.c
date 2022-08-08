/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_pixels.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 13:49:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 15:56:05 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_pixels(t_it_frame_pixels *it,
						mlx_image_t *frame, t_data *data)
{
	while (true)
	{
		if (sl_iterate_frame_width(&it->width_it, frame, data) != FINISHED)
			return (LOOPED);
		if (data->it.frame_pixels.y == 0)
			sl_iterate_frame_height(&it->height_it, frame, data);
		if (sl_iterate_frame_height(&it->height_it, frame, data) == FINISHED)
			break ;
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_init_it_frame_pixels(t_it_frame_pixels *it)
{
	ft_bzero(it, sizeof(t_it_frame_pixels));
}

////////////////////////////////////////////////////////////////////////////////
