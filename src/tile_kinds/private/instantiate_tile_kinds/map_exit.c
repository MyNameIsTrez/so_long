/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_exit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:05:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 18:04:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_thing_tile_kind/sl_private_add_thing_tile_kind.h"
#include "add_thing_tile_kind/add_tile_kind/sl_private_tile_kind_data.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_map_exit_tile_kind(t_data *data)
{
	const t_tile_kind_data	tk_data = {
		.character = MAP_EXIT_CHARACTER,
		.is_entity = MAP_EXIT_IS_ENTITY,
		.frame_count = MAP_EXIT_TEXTURE_FRAME_COUNT,
		.texture_row = MAP_EXIT_TEXTURE_ROW,
		.depth = MAP_EXIT_DEPTH,
		.ticks_between_frame_changes = MAP_EXIT_TICKS_BETWEEN_FRAME_CHANGES,
		.ticks_between_updates = MAP_EXIT_TICKS_BETWEEN_UPDATES,
		(t_tile_kind_color){
	{MAP_EXIT_R, MAP_EXIT_G, MAP_EXIT_B},
	{MAP_EXIT_MIN_R, MAP_EXIT_MIN_G, MAP_EXIT_MIN_B},
	{MAP_EXIT_MAX_R, MAP_EXIT_MAX_G, MAP_EXIT_MAX_B},
	{MAP_EXIT_R_WAIT, MAP_EXIT_G_WAIT, MAP_EXIT_B_WAIT},
	{MAP_EXIT_R_STEP, MAP_EXIT_G_STEP, MAP_EXIT_B_STEP}}};

	if (add_tile_kind(tk_data, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
