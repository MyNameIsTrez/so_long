/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window_height.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:25:26 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:26:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	init_window_height(size_t pixels_per_tile, t_data *data)
{
	data->window.height = data->char_grid.height * pixels_per_tile;
	if (data->window.height > data->monitor.height)
		data->window.height = data->monitor.height;
}

////////////////////////////////////////////////////////////////////////////////
