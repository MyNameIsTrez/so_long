/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_tile_kinds_colors.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 17:52:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 19:27:04 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/initialize_tile_kinds_colors/\
sl_private_initialize_tile_kinds_colors.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_initialize_tile_kinds_colors(t_data *data)
{
	t_iterator	tile_kind_it;
	t_iterator	frames_it;

	ft_init_it(&tile_kind_it);
	ft_init_it(&frames_it);
	// TODO: Create and use sl_iterate_tile_kinds_frames() here and in the other sl_iterate_frames() spot
	while (sl_iterate_tile_kinds(&tile_kind_it, data) != FINISHED)
		while (sl_iterate_frames(&frames_it, data->it.tile_kind,
				data) != FINISHED)
			initialize_visible_frames(data->it.frame, data);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
