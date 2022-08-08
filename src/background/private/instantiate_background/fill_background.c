/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_background.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 17:43:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 16:31:43 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	fill_background(mlx_image_t *background, t_data *data)
{
	t_it_frame_pixels	it;
	size_t				pixel_index;
	t_u8 const			color[] = {
		BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, 255};

	sl_init_it_frame_pixels(&it);
	while (sl_iterate_frame_pixels(&it, background, data) != FINISHED)
	{
		pixel_index = sl_get_pixel_index(background, data);
		ft_memcpy(&background->pixels[pixel_index], color, 4);
	}
}

////////////////////////////////////////////////////////////////////////////////
