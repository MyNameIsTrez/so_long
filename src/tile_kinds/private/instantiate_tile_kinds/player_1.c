/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_1.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:03:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 16:25:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_thing_tile_kind/sl_private_add_thing_tile_kind.h"
#include "add_thing_tile_kind/add_tile_kind/sl_private_tile_kind_data.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_player_1_tile_kind(t_data *data)
{
	t_tile_kind_data const	tk_data = {
		.character = PLAYER_1_CHARACTER,
		.is_entity = PLAYER_1_IS_ENTITY,
		.frame_count = PLAYER_1_TEXTURE_FRAME_COUNT,
		.texture_row = PLAYER_1_TEXTURE_ROW,
		.depth = PLAYER_1_DEPTH,
		.ticks_between_frame_changes = PLAYER_TICKS_BETWEEN_FRAME_CHANGES,
		.ticks_between_updates = PLAYER_TICKS_BETWEEN_UPDATES,
		(t_tile_kind_color){
	{PLAYER_1_R, PLAYER_1_G, PLAYER_1_B},
	{PLAYER_1_MIN_R, PLAYER_1_MIN_G, PLAYER_1_MIN_B},
	{PLAYER_1_MAX_R, PLAYER_1_MAX_G, PLAYER_1_MAX_B},
	{PLAYER_1_R_WAIT, PLAYER_1_G_WAIT, PLAYER_1_B_WAIT},
	{PLAYER_1_R_STEP, PLAYER_1_G_STEP, PLAYER_1_B_STEP}}};

	if (add_tile_kind(tk_data, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
