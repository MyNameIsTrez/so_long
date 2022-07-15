/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_tile_kinds_colors.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 17:52:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/15 14:21:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_initialize_tile_kinds_colors(t_data *data)
{
	sl_reset_iterate_tile_kinds(data);
	while (sl_iterate_tile_kinds(data) != FINISHED)
	{
		while (sl_iterate_frames_byte_indices(data->it.tile_kind, data) != FINISHED)
		{
			data->it.frame->pixels[data->it.frame_byte_index] = 200;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
