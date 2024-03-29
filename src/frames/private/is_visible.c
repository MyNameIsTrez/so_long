/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_visible.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 19:28:43 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 19:32:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	is_visible(mlx_image_t *frame, t_data *data)
{
	t_u8	*pixels;
	t_u8	alpha;

	pixels = frame->pixels;
	alpha = pixels[data->it.frame_pixel_index + 3];
	return (alpha > 0);
}

////////////////////////////////////////////////////////////////////////////////
