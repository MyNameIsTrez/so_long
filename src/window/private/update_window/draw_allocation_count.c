/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_allocation_count.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/15 15:29:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 16:11:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../../submodules/MLX42/src/font/font.h"
#include "get_draw_string/sl_private_get_draw_string.h"

////////////////////////////////////////////////////////////////////////////////

t_status	draw_allocation_count(t_data *data)
{
	static mlx_image_t	*image;
	char				*string;

	if (image != NULL)
		mlx_delete_image(data->mlx, image);
	if (!data->window.draw_debug)
		return (OK);
	string = get_allocation_count_string();
	if (string == NULL)
		return (ERROR);
	image = mlx_put_string(data->mlx, string, 0, FONT_HEIGHT);
	ft_free(&string);
	if (image == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	mlx_set_instance_depth(&image->instances[0], DEBUG_DRAWING_DEPTH);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
