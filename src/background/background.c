/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   background.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 12:05:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/13 13:01:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	fill_background(mlx_image_t *background, t_data *data)
{
	while (sl_iterate_frame_pixels(background, data) != FINISHED)
	{
		ft_memcpy(&background->pixels[sl_get_pixel_index(background, data)], (uint8_t[]){0, 0, 0, 255}, 4);
	}
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_background(t_data *data)
{
	mlx_image_t	*background;
	int32_t		background_instance_index;

	background = mlx_new_image(data->mlx, data->window.width, data->window.height);
	if (background == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	fill_background(background, data);
	background_instance_index = mlx_image_to_window(data->mlx, background, 0, 0);
	if (background_instance_index < 0)
		return (sl_set_error(SL_ERROR_MLX42));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
