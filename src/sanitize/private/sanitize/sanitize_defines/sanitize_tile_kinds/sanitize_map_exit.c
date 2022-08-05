/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_map_exit.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:53:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 15:27:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_private_sanitize_defines.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_map_exit(t_data *data)
{
	const t_tile_kind_data_color	tile_kind_data_color = {
		.initial_color = {MAP_EXIT_R, MAP_EXIT_G, MAP_EXIT_B},
		.min_color_offset = {MAP_EXIT_MIN_R_OFFSET, MAP_EXIT_MIN_G_OFFSET,
		MAP_EXIT_MIN_B_OFFSET},
		.max_color_offset = {MAP_EXIT_MAX_R_OFFSET, MAP_EXIT_MAX_G_OFFSET,
		MAP_EXIT_MAX_B_OFFSET},
		.wait = {MAP_EXIT_R_WAIT, MAP_EXIT_G_WAIT, MAP_EXIT_B_WAIT},
		.step = {MAP_EXIT_R_STEP, MAP_EXIT_G_STEP, MAP_EXIT_B_STEP}
	};

	if (sanitize_tile_kind(tile_kind_data_color, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
