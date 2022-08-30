/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:03:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 16:25:30 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_thing_tile_kind/sl_private_add_thing_tile_kind.h"
#include "add_thing_tile_kind/add_tile_kind/sl_private_tile_kind_data.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_player_2_tile_kind(t_data *data)
{
	t_tile_kind_data const	tk_data = {
		.character = PLAYER_2_CHARACTER,
		.is_entity = PLAYER_2_IS_ENTITY,
		.frame_count = PLAYER_2_TEXTURE_FRAME_COUNT,
		.texture_row = PLAYER_2_TEXTURE_ROW,
		.depth = PLAYER_2_DEPTH,
		.ticks_between_frame_changes = PLAYER_TICKS_BETWEEN_FRAME_CHANGES,
		.ticks_between_updates = PLAYER_TICKS_BETWEEN_UPDATES,
		(t_tile_kind_color){
	{PLAYER_2_R, PLAYER_2_G, PLAYER_2_B},
	{PLAYER_2_MIN_R, PLAYER_2_MIN_G, PLAYER_2_MIN_B},
	{PLAYER_2_MAX_R, PLAYER_2_MAX_G, PLAYER_2_MAX_B},
	{PLAYER_2_R_WAIT, PLAYER_2_G_WAIT, PLAYER_2_B_WAIT},
	{PLAYER_2_R_STEP, PLAYER_2_G_STEP, PLAYER_2_B_STEP}}};

	if (add_tile_kind(tk_data, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
