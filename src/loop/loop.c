/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 13:56:49 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 15:52:30 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_loop(void *param)
{
	t_data				*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->mlx);
		return ;
	}
	sl_update_held_keys(data);
	if (!data->finished_level)
	{
		sl_change_frames(data);
		sl_update_entities(data);
	}
	sl_update_frame_colors(data);
	if (sl_update_window(data) != OK)
		mlx_close_window(data->mlx);
	data->ticks++;
}

////////////////////////////////////////////////////////////////////////////////
