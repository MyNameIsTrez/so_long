/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 13:51:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 14:36:33 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_init(t_i32 argc, char **argv, t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	if (sl_sanitize(data) != OK)
		return (sl_any_error());
	sl_init_monitor_size(data);
	if (sl_parse_argv(argc, argv, data) != OK)
		return (sl_any_error());
	data->mlx = mlx_init((t_i32)data->window.width, (t_i32)data->window.height,
			WINDOW_TITLE, false);
	if (data->mlx == NULL)
		return (sl_set_error(SL_ERROR_MLX42));
	if (sl_subinits(data) != OK)
		return (sl_any_error());
	if (mlx_loop_hook(data->mlx, sl_loop, data) != true)
		return (sl_set_error(SL_ERROR_MLX42));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
