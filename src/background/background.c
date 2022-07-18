/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   background.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 12:05:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/18 12:42:37 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	fill_background(mlx_image_t *background, t_data *data)
{
	t_i32		pixel_index;
	t_u8 const	color[] = {BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, 255};

	while (sl_iterate_frame_pixels(background, data) != FINISHED)
	{
		pixel_index = sl_get_pixel_index(background, data);
		ft_memcpy(&background->pixels[pixel_index], color, 4);
	}
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_background(t_data *data)
{
	mlx_image_t	*background;
	t_i32		background_instance_index;

	background = mlx_new_image(data->mlx,
			(t_u32)data->window.width, (t_u32)data->window.height);
	if (background == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	fill_background(background, data);
	background_instance_index = mlx_image_to_window(data->mlx, background,
			0, 0);
	if (background_instance_index < 0)
		return (sl_set_error(SL_ERROR_MLX42));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
