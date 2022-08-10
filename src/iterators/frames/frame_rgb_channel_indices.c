/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_rgb_channel_indices.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 12:12:41 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/10 17:09:24 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_rgb_channel_indices(
						t_it_frame_rgb_channel_indices *it, mlx_image_t *frame,
						t_data *data)
{
	if (!it->frame_pixel_indices_it.initialized)
		sl_iterate_frame_pixel_indices(&it->frame_pixel_indices_it, frame, data);
	while (true)
	{
		if (sl_iterate_rgb_channel_indices(&it->rgb_channel_indices_it, data) != FINISHED)
			return (LOOPED);
		if (sl_iterate_frame_pixel_indices(&it->frame_pixel_indices_it, frame, data) == FINISHED)
			break ;
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_init_it_frame_rgb_channel_indices(t_it_frame_rgb_channel_indices *it)
{
	ft_bzero(it, sizeof(t_it_frame_rgb_channel_indices));
}

////////////////////////////////////////////////////////////////////////////////
