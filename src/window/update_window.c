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

t_status	sl_update_window(t_data *data)
{
	if (data->held_keys[TOGGLE_DEBUG_DRAWING_KEY] == 1)
		data->window.draw_debug = !data->window.draw_debug;
	if (draw_fps(data) != OK)
		return (ERROR);
	if (draw_allocation_count(data) != OK)
		return (ERROR);
	if (draw_movement_count(data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
