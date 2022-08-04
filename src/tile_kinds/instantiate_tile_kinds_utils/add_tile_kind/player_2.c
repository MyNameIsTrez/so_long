/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:03:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/04 13:44:04 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_instantiate_tile_kinds_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_player_2_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			PLAYER_2_TEXTURE_FRAME_COUNT,
			PLAYER_2_TEXTURE_ROW,
			PLAYER_2_CHARACTER,
			PLAYER_2_DEPTH,
			(t_tile_kind_data_color){
			{PLAYER_2_R, PLAYER_2_G, PLAYER_2_B},
			{PLAYER_2_MIN_R_OFFSET, PLAYER_2_MIN_G_OFFSET,
				PLAYER_2_MIN_B_OFFSET},
			{PLAYER_2_MAX_R_OFFSET, PLAYER_2_MAX_G_OFFSET,
				PLAYER_2_MAX_B_OFFSET},
			{PLAYER_2_R_WAIT, PLAYER_2_G_WAIT, PLAYER_2_B_WAIT},
			{PLAYER_2_R_STEP, PLAYER_2_G_STEP, PLAYER_2_B_STEP}}},
			data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
