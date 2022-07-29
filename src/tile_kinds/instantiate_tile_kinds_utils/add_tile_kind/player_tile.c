/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_player_tile_kind.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:03:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:04:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_instantiate_tile_kinds_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_player_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			PLAYER_TEXTURE_FRAME_COUNT,
			PLAYER_TEXTURE_ROW,
			PLAYER_CHARACTER,
			PLAYER_DEPTH,
			(t_tile_kind_color){
			{PLAYER_R, PLAYER_G, PLAYER_B},
			{PLAYER_MIN_R, PLAYER_MIN_G, PLAYER_MIN_B},
			{PLAYER_MAX_R, PLAYER_MAX_G, PLAYER_MAX_B},
			{PLAYER_R_WAIT, PLAYER_G_WAIT, PLAYER_B_WAIT},
			{PLAYER_R_STEP, PLAYER_G_STEP, PLAYER_B_STEP}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
