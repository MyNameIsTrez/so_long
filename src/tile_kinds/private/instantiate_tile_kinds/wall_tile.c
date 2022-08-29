/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_tile.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:06:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 18:04:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_thing_tile_kind/sl_private_add_thing_tile_kind.h"
#include "add_thing_tile_kind/add_tile_kind/sl_private_tile_kind_data.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_wall_tile_kind(t_data *data)
{
	const t_tile_kind_data	tk_data = {
		.character = WALL_CHARACTER,
		.is_entity = WALL_IS_ENTITY,
		.frame_count = WALL_TEXTURE_FRAME_COUNT,
		.texture_row = WALL_TEXTURE_ROW,
		.depth = WALL_DEPTH,
		.ticks_between_frame_changes = WALL_TICKS_BETWEEN_FRAME_CHANGES,
		.ticks_between_updates = WALL_TICKS_BETWEEN_UPDATES,
		(t_tile_kind_color){
	{WALL_R, WALL_G, WALL_B},
	{WALL_MIN_R, WALL_MIN_G, WALL_MIN_B},
	{WALL_MAX_R, WALL_MAX_G, WALL_MAX_B},
	{WALL_R_WAIT, WALL_G_WAIT, WALL_B_WAIT},
	{WALL_R_STEP, WALL_G_STEP, WALL_B_STEP}}};

	if (add_tile_kind(tk_data, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
