/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_movement_count.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/15 13:38:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 16:11:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../../submodules/MLX42/src/font/font.h"
#include "get_draw_string/sl_private_get_draw_string.h"

////////////////////////////////////////////////////////////////////////////////

t_status	draw_movement_count(t_data *data)
{
	static mlx_image_t	*image;
	char				*string;

	if (image != NULL)
		mlx_delete_image(data->mlx, image);
	if (!data->window.draw_debug)
		return (OK);
	string = get_movement_count_string(data);
	if (string == NULL)
		return (ERROR);
	image = mlx_put_string(data->mlx, string, 0, 2 * FONT_HEIGHT);
	ft_free(&string);
	if (image == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	mlx_set_instance_depth(&image->instances[0], DEBUG_DRAWING_DEPTH);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
