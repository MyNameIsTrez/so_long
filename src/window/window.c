/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 14:19:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 14:19:24 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_calculate_window_width_and_height(t_data *data)
{
	size_t	pixels_per_tile;

	pixels_per_tile = data->texture.pixels_per_tile;
	data->window.width = data->char_grid.width * pixels_per_tile;
	if (data->window.width > data->monitor.width)
		data->window.width = data->monitor.width;
	data->window.height = data->char_grid.height * pixels_per_tile;
	if (data->window.height > data->monitor.height)
		data->window.height = data->monitor.height;
}

////////////////////////////////////////////////////////////////////////////////
