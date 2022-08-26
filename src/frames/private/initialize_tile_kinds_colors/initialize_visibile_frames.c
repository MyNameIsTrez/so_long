/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_visibile_frames.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 19:09:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 19:27:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_private_frames.h"
#include "initialize_visible_frames/sl_private_initialize_visible_frames.h"

////////////////////////////////////////////////////////////////////////////////

void	initialize_visible_frames(mlx_image_t *frame, t_data *data)
{
	t_iterator	frame_pixel_indices_it;
	t_u8		*pixels;

	ft_init_it(&frame_pixel_indices_it);
	pixels = frame->pixels;
	while (sl_iterate_frame_pixel_indices(&frame_pixel_indices_it, frame,
			data) != FINISHED)
		if (is_visible(frame, data))
			initialize_channels(pixels, data);
}

////////////////////////////////////////////////////////////////////////////////
