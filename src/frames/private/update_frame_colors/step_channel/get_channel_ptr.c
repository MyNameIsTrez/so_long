/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_channel_ptr.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 17:40:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 18:14:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_u8	*get_channel_ptr(size_t rgb_channel_index, mlx_image_t *frame,
			t_data *data)
{
	t_u8	*pixels;

	pixels = frame->pixels;
	return (&pixels[data->it.frame_pixel_index + rgb_channel_index]);
}

////////////////////////////////////////////////////////////////////////////////
