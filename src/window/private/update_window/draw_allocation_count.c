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

////////////////////////////////////////////////////////////////////////////////

void	draw_allocation_count(t_data *data)
{
	static mlx_image_t	*image;
	char				*string;
	char				*string_full;

	if (image != NULL)
		mlx_delete_image(data->mlx, image);
	if (!data->window.draw_debug)
		return ;
	string = ft_itoa((t_i32)ft_get_allocation_count());
	if (string == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	string_full = ft_strjoin("Allocation count: ", string);
	ft_free(&string);
	if (string_full == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	image = mlx_put_string(data->mlx, string_full, 0, FONT_HEIGHT); // TODO: Should this be checked for any error?
	mlx_set_instance_depth(&image->instances[0], DEBUG_DRAWING_DEPTH);
	ft_free(&string_full);
}

////////////////////////////////////////////////////////////////////////////////
