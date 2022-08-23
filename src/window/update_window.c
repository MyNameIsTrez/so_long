/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_window.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 15:09:28 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 15:30:03 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/update_window/sl_private_update_window.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_window(t_data *data)
{
	if (data->held_keys[TOGGLE_DEBUG_DRAWING_KEY] == 1)
		data->window.draw_debug = !data->window.draw_debug;
	draw_fps(data);
	draw_allocation_count(data);
	draw_movement_count(data);
}

////////////////////////////////////////////////////////////////////////////////
