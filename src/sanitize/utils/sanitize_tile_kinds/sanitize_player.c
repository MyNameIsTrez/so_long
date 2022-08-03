/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_player.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:53:02 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 15:08:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_sanitize_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_player(t_data *data)
{
	const t_tile_kind_data_color	tile_kind_data_color = {
		.initial_color = {PLAYER_R, PLAYER_G, PLAYER_B},
		.min_color_offset = {PLAYER_MIN_R_OFFSET, PLAYER_MIN_G_OFFSET,
		PLAYER_MIN_B_OFFSET},
		.max_color_offset = {PLAYER_MAX_R_OFFSET, PLAYER_MAX_G_OFFSET,
		PLAYER_MAX_B_OFFSET},
		.wait = {PLAYER_R_WAIT, PLAYER_G_WAIT, PLAYER_B_WAIT},
		.step = {PLAYER_R_STEP, PLAYER_G_STEP, PLAYER_B_STEP}
	};

	if (sanitize_tile_kind(tile_kind_data_color, data) != OK)
		return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
