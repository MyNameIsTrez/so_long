/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_background.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 12:05:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 15:32:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/instantiate_background/sl_private_instantiate_background.h"

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
	mlx_set_instance_depth(&background->instances[background_instance_index],
		BACKGROUND_DEPTH);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
