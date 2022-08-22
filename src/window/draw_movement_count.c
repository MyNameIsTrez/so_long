/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_movement_count.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/15 13:38:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/22 17:32:23 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../../submodules/MLX42/src/font/font.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_draw_movement_count(t_data *data)
{
	static mlx_image_t	*movement_count_image;
	char				*movement_count_string;
	char				*movement_count_string_full;

	if (movement_count_image == NULL)
	{
		movement_count_image = mlx_new_image(data->mlx, 1000, FONT_HEIGHT); // TODO: DONT HARDCODE THE STRING WIDTH TO 1000
		if (movement_count_image == NULL)
			return ;
		if (mlx_image_to_window(data->mlx, movement_count_image, 0, 2 * FONT_HEIGHT) == -1)
		{
			sl_cleanup(data);
			sl_print_all_errors();
			return ;
		}
	}
	movement_count_string = ft_itoa((t_i32)data->movement_count);
	if (movement_count_string == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	movement_count_string_full = ft_strjoin("Movement count: ", movement_count_string);
	ft_free(&movement_count_string);
	if (movement_count_string_full == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	mlx_put_string2(data->mlx, movement_count_string_full, movement_count_image); // TODO: Should this be checked for any error?
	ft_free(&movement_count_string_full);
}

////////////////////////////////////////////////////////////////////////////////
