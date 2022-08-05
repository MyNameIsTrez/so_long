/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_player_1.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:53:02 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 18:13:33 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sanitize_thing_tile_kind/sl_private_sanitize_thing_tile_kind.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_player_1(t_data *data)
{
	const t_tile_kind_data_color	tile_kind_data_color = {
		.initial_color = {PLAYER_1_R, PLAYER_1_G, PLAYER_1_B},
		.min_color_offset = {PLAYER_1_MIN_R_OFFSET, PLAYER_1_MIN_G_OFFSET,
		PLAYER_1_MIN_B_OFFSET},
		.max_color_offset = {PLAYER_1_MAX_R_OFFSET, PLAYER_1_MAX_G_OFFSET,
		PLAYER_1_MAX_B_OFFSET},
		.wait = {PLAYER_1_R_WAIT, PLAYER_1_G_WAIT, PLAYER_1_B_WAIT},
		.step = {PLAYER_1_R_STEP, PLAYER_1_G_STEP, PLAYER_1_B_STEP}
	};

	if (sanitize_tile_kind(tile_kind_data_color, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
