/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_space.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:06:39 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 18:04:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_thing_tile_kind/sl_private_add_thing_tile_kind.h"
#include "add_thing_tile_kind/add_tile_kind/sl_private_tile_kind_data.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_empty_space_tile_kind(t_data *data)
{
	t_tile_kind_data const	tk_data = {
		.character = EMPTY_SPACE_CHARACTER,
		.is_entity = EMPTY_SPACE_IS_ENTITY,
		.frame_count = EMPTY_SPACE_TEXTURE_FRAME_COUNT,
		.texture_row = EMPTY_SPACE_TEXTURE_ROW,
		.depth = EMPTY_SPACE_DEPTH,
		.ticks_between_frame_changes = EMPTY_SPACE_TICKS_BETWEEN_FRAME_CHANGES,
		.ticks_between_updates = EMPTY_SPACE_TICKS_BETWEEN_UPDATES,
		(t_tile_kind_color){
	{EMPTY_SPACE_R, EMPTY_SPACE_G, EMPTY_SPACE_B},
	{EMPTY_SPACE_MIN_R, EMPTY_SPACE_MIN_G, EMPTY_SPACE_MIN_B},
	{EMPTY_SPACE_MAX_R, EMPTY_SPACE_MAX_G, EMPTY_SPACE_MAX_B},
	{EMPTY_SPACE_R_WAIT, EMPTY_SPACE_G_WAIT, EMPTY_SPACE_B_WAIT},
	{EMPTY_SPACE_R_STEP, EMPTY_SPACE_G_STEP, EMPTY_SPACE_B_STEP}}};

	if (add_tile_kind(tk_data, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
