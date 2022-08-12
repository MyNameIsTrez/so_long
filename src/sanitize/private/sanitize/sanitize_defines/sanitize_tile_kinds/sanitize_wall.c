/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_wall.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:52:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 11:27:55 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sanitize_thing_tile_kind/sl_private_sanitize_thing_tile_kind.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_wall(t_data *data)
{
	const t_tile_kind_data_color	tile_kind_data_color = {
		.initial_color = {WALL_R, WALL_G, WALL_B},
		.min_color = {WALL_MIN_R, WALL_MIN_G, WALL_MIN_B},
		.max_color = {WALL_MAX_R, WALL_MAX_G, WALL_MAX_B},
		.wait = {WALL_R_WAIT, WALL_G_WAIT, WALL_B_WAIT},
		.step = {WALL_R_STEP, WALL_G_STEP, WALL_B_STEP}
	};

	if (sanitize_tile_kind(tile_kind_data_color, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
