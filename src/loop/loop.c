/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 13:56:49 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 19:00:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_loop(void *param)
{
	static mlx_image_t	*fps_image; // TODO: Move this into data?
	char				*fps_string;
	t_data				*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	sl_update_frame_colors(data);
	sl_update_held_keys(data);
	sl_update_entities(data);
	sl_change_frames(data);
	if (fps_image != NULL)
		mlx_delete_image(data->mlx, fps_image);
	fps_string = ft_strjoin(ft_itoa((t_i32)(1 / data->mlx->delta_time)), "/60 FPS");
	if (fps_string == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	fps_image = mlx_put_string(data->mlx, fps_string, 0, 0); // TODO: Should this be checked for any error?
	data->ticks++;
}

////////////////////////////////////////////////////////////////////////////////
