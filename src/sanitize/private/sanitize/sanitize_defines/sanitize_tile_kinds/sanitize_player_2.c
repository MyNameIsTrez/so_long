/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_player_2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:53:02 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 15:27:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_private_sanitize_defines.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_player_2(t_data *data)
{
	const t_tile_kind_data_color	tile_kind_data_color = {
		.initial_color = {PLAYER_2_R, PLAYER_2_G, PLAYER_2_B},
		.min_color_offset = {PLAYER_2_MIN_R_OFFSET, PLAYER_2_MIN_G_OFFSET,
		PLAYER_2_MIN_B_OFFSET},
		.max_color_offset = {PLAYER_2_MAX_R_OFFSET, PLAYER_2_MAX_G_OFFSET,
		PLAYER_2_MAX_B_OFFSET},
		.wait = {PLAYER_2_R_WAIT, PLAYER_2_G_WAIT, PLAYER_2_B_WAIT},
		.step = {PLAYER_2_R_STEP, PLAYER_2_G_STEP, PLAYER_2_B_STEP}
	};

	if (sanitize_tile_kind(tile_kind_data_color, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
