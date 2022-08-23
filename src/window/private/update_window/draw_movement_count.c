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

////////////////////////////////////////////////////////////////////////////////

void	draw_movement_count(t_data *data)
{
	static mlx_image_t	*image;
	char				*string;
	char				*string_full;

	if (image != NULL)
		mlx_delete_image(data->mlx, image);
	if (!data->window.draw_debug)
		return ;
	string = ft_itoa((t_i32)data->movement_count);
	if (string == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	string_full = ft_strjoin("Movement count: ", string);
	ft_free(&string);
	if (string_full == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	image = mlx_put_string(data->mlx, string_full, 0, 2 * FONT_HEIGHT); // TODO: Should this be checked for any error?
	mlx_set_instance_depth(&image->instances[0], DEBUG_DRAWING_DEPTH);
	ft_free(&string_full);
}

////////////////////////////////////////////////////////////////////////////////
