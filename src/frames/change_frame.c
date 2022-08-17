/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   change_frame.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 17:43:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/17 17:49:45 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_change_frame(t_tile *tile, size_t new_frame_index)
{
	sl_get_frame_instance(tile, tile->frame_index)->enabled = false;
	tile->frame_index = new_frame_index;
	sl_get_frame_instance(tile, tile->frame_index)->enabled = true;
}

////////////////////////////////////////////////////////////////////////////////
