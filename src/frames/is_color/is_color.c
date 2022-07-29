/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_color.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 16:14:48 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 16:20:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC bool	sl_is_opaque(t_data *data)
{
	mlx_image_t	*frame;
	t_u8		*pixels;

	frame = data->it.frame;
	pixels = frame->pixels;
	return (pixels[data->it.pixel_index + 3] > 0);
}

STATIC bool	sl_is_background(t_data *data)
{
	static const t_u8	color[] = {
		BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, 255};
	mlx_image_t			*frame;
	t_u8				*pixels;

	frame = data->it.frame;
	pixels = frame->pixels;
	return (ft_memcmp(&pixels[data->it.pixel_index], color, 4) == 0);
}

////////////////////////////////////////////////////////////////////////////////

bool	sl_is_color(t_data *data)
{
	return (sl_is_opaque(data) && !sl_is_background(data));
}

////////////////////////////////////////////////////////////////////////////////
