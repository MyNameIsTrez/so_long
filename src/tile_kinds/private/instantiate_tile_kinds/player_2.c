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
	if (add_tile_kind((t_tile_kind_data){
			PLAYER_2_TEXTURE_FRAME_COUNT,
			PLAYER_2_TEXTURE_ROW,
			PLAYER_2_CHARACTER,
			PLAYER_2_IS_ENTITY,
			PLAYER_2_DEPTH,
			PLAYER_TICKS_BETWEEN_FRAME_CHANGES,
			PLAYER_TICKS_BETWEEN_UPDATES,
			(t_tile_kind_color){
			{PLAYER_2_R, PLAYER_2_G, PLAYER_2_B},
			{PLAYER_2_MIN_R, PLAYER_2_MIN_G, PLAYER_2_MIN_B},
			{PLAYER_2_MAX_R, PLAYER_2_MAX_G, PLAYER_2_MAX_B},
			{PLAYER_2_R_WAIT, PLAYER_2_G_WAIT, PLAYER_2_B_WAIT},
			{PLAYER_2_R_STEP, PLAYER_2_G_STEP, PLAYER_2_B_STEP}}},
			data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
