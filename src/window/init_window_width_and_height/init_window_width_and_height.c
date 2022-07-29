/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window_width_and_height.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 15:29:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	sl_calculate_window_width(size_t pixels_per_tile, t_data *data)
{
	data->window.width = data->char_grid.width * pixels_per_tile;
	if (data->window.width > data->monitor.width)
		data->window.width = data->monitor.width;
}

STATIC void	sl_calculate_window_height(size_t pixels_per_tile, t_data *data)
{
	data->window.height = data->char_grid.height * pixels_per_tile;
	if (data->window.height > data->monitor.height)
		data->window.height = data->monitor.height;
}

////////////////////////////////////////////////////////////////////////////////

void	sl_init_window_width_and_height(t_data *data)
{
	size_t	pixels_per_tile;

	pixels_per_tile = data->texture.pixels_per_tile;
	sl_calculate_window_width(pixels_per_tile, data);
	sl_calculate_window_height(pixels_per_tile, data);
}

////////////////////////////////////////////////////////////////////////////////
