/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 13:56:49 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 13:56:55 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_loop(void *param)
{
	t_data	*data;

	data = param;
	data->seconds += data->mlx->delta_time;
	// ft_printf("%d\n", data->seconds);
	// ft_printf("%d\n", data->frame);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	// sl_update_frame_colors(data);
	sl_try_move_players(data);
	sl_update_held_keys(data);
	sl_change_frames(data);
	data->frame++;
}

////////////////////////////////////////////////////////////////////////////////
