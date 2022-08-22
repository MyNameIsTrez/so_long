/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_fps.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/15 13:38:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/22 17:31:33 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../../submodules/MLX42/src/font/font.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_draw_fps(t_data *data)
{
	static mlx_image_t	*fps_image;
	char				*fps_string;
	char				*fps_string_full;

	if (fps_image == NULL)
	{
		fps_image = mlx_new_image(data->mlx, 1000, FONT_HEIGHT); // TODO: DONT HARDCODE THE STRING WIDTH TO 1000
		if (fps_image == NULL)
			return ;
		if (mlx_image_to_window(data->mlx, fps_image, 0, 0) == -1)
		{
			sl_cleanup(data);
			sl_print_all_errors();
			return ;
		}
	}
	fps_string = ft_itoa((t_i32)(1 / data->mlx->delta_time));
	if (fps_string == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	fps_string_full = ft_strjoin(fps_string, " FPS");
	ft_free(&fps_string);
	if (fps_string_full == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	mlx_put_string2(data->mlx, fps_string_full, fps_image); // TODO: Should this be checked for any error?
	ft_free(&fps_string_full);
}

////////////////////////////////////////////////////////////////////////////////
