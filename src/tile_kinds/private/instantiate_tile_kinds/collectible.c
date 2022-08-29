/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:05:52 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 18:03:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_thing_tile_kind/sl_private_add_thing_tile_kind.h"
#include "add_thing_tile_kind/add_tile_kind/sl_private_tile_kind_data.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_collectible_tile_kind(t_data *data)
{
	const t_tile_kind_data	tk_data = {
		.character = COLLECTIBLE_CHARACTER,
		.is_entity = COLLECTIBLE_IS_ENTITY,
		.frame_count = COLLECTIBLE_TEXTURE_FRAME_COUNT,
		.texture_row = COLLECTIBLE_TEXTURE_ROW,
		.depth = COLLECTIBLE_DEPTH,
		.ticks_between_frame_changes = COLLECTIBLE_TICKS_BETWEEN_FRAME_CHANGES,
		.ticks_between_updates = COLLECTIBLE_TICKS_BETWEEN_UPDATES,
		(t_tile_kind_color){
	{COLLECTIBLE_R, COLLECTIBLE_G, COLLECTIBLE_B},
	{COLLECTIBLE_MIN_R, COLLECTIBLE_MIN_G, COLLECTIBLE_MIN_B},
	{COLLECTIBLE_MAX_R, COLLECTIBLE_MAX_G, COLLECTIBLE_MAX_B},
	{COLLECTIBLE_R_WAIT, COLLECTIBLE_G_WAIT, COLLECTIBLE_B_WAIT},
	{COLLECTIBLE_R_STEP, COLLECTIBLE_G_STEP, COLLECTIBLE_B_STEP}}};

	if (add_tile_kind(tk_data, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
