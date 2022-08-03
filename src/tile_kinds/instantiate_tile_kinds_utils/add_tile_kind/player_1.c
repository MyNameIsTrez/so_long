/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_1.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:03:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 16:53:04 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_instantiate_tile_kinds_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_player_1_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			PLAYER_1_TEXTURE_FRAME_COUNT,
			PLAYER_1_TEXTURE_ROW,
			PLAYER_CHARACTER,
			PLAYER_1_DEPTH,
			(t_tile_kind_data_color){
			{PLAYER_1_R, PLAYER_1_G, PLAYER_1_B},
			{PLAYER_1_MIN_R_OFFSET, PLAYER_1_MIN_G_OFFSET,
				PLAYER_1_MIN_B_OFFSET},
			{PLAYER_1_MAX_R_OFFSET, PLAYER_1_MAX_G_OFFSET,
				PLAYER_1_MAX_B_OFFSET},
			{PLAYER_1_R_WAIT, PLAYER_1_G_WAIT, PLAYER_1_B_WAIT},
			{PLAYER_1_R_STEP, PLAYER_1_G_STEP, PLAYER_1_B_STEP}}},
			data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
