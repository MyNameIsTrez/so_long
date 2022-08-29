/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monster.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 15:00:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 18:04:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_thing_tile_kind/sl_private_add_thing_tile_kind.h"
#include "add_thing_tile_kind/add_tile_kind/sl_private_tile_kind_data.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_monster_tile_kind(t_data *data)
{
	const t_tile_kind_data	tk_data = {
		.character = MONSTER_CHARACTER,
		.is_entity = MONSTER_IS_ENTITY,
		.frame_count = MONSTER_TEXTURE_FRAME_COUNT,
		.texture_row = MONSTER_TEXTURE_ROW,
		.depth = MONSTER_DEPTH,
		.ticks_between_frame_changes = MONSTER_TICKS_BETWEEN_FRAME_CHANGES,
		.ticks_between_updates = MONSTER_TICKS_BETWEEN_UPDATES,
		(t_tile_kind_color){
	{MONSTER_R, MONSTER_G, MONSTER_B},
	{MONSTER_MIN_R, MONSTER_MIN_G, MONSTER_MIN_B},
	{MONSTER_MAX_R, MONSTER_MAX_G, MONSTER_MAX_B},
	{MONSTER_R_WAIT, MONSTER_G_WAIT, MONSTER_B_WAIT},
	{MONSTER_R_STEP, MONSTER_G_STEP, MONSTER_B_STEP}}};

	if (add_tile_kind(tk_data, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
