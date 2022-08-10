/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_background.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 17:43:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/10 16:43:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	fill_background(mlx_image_t *background, t_data *data)
{
	t_iterator	it;
	t_u8 const	color[] = {BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, 255};

	ft_init_it(&it);
	while (sl_iterate_frame_pixel_indices(&it, background, data) != FINISHED)
		ft_memcpy(&background->pixels[data->it.frame_pixel_index], color, 4);
}

////////////////////////////////////////////////////////////////////////////////
