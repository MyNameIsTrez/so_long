/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_monitor_size.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 13:31:14 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_init_monitor_size(t_data *data)
{
	t_i32	width;
	t_i32	height;

	mlx_get_monitor_size(0, &width, &height);
	if (width <= 0)
		width = MAX_MONITOR_WIDTH;
	if (height <= 0)
		height = MAX_MONITOR_HEIGHT;
	data->monitor.width = (size_t)width;
	data->monitor.height = (size_t)height;
}

////////////////////////////////////////////////////////////////////////////////
