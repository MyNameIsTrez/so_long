/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_fps.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/15 13:38:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/15 15:55:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_draw_fps(t_data *data)
{
	static mlx_image_t	*fps_image;
	char				*fps_string;
	char				*fps_string_full;

	if (fps_image != NULL)
		mlx_delete_image(data->mlx, fps_image);
	fps_string = ft_itoa((t_i32)(1 / data->mlx->delta_time));
	if (fps_string == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	fps_string_full = ft_strjoin(fps_string, "/60 FPS"); // TODO: Should ft_itoa() be checked for any error?
	ft_free(&fps_string);
	if (fps_string_full == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	fps_image = mlx_put_string(data->mlx, fps_string_full, 0, 0); // TODO: Should this be checked for any error?
	ft_free(&fps_string_full);
}

////////////////////////////////////////////////////////////////////////////////
