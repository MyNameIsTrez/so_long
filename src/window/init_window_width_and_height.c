/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window_width_and_height.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 15:29:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 18:22:54 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/init_window_width_and_height/sl_private_init_window_width_and_height.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_init_window_width_and_height(t_data *data)
{
	size_t	pixels_per_tile;

	pixels_per_tile = data->texture.pixels_per_tile;
	init_window_width(pixels_per_tile, data);
	init_window_height(pixels_per_tile, data);
}

////////////////////////////////////////////////////////////////////////////////
