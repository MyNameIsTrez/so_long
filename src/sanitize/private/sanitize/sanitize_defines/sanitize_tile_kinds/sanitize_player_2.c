/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_player_2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:53:02 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 11:27:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sanitize_thing_tile_kind/sl_private_sanitize_thing_tile_kind.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_player_2(t_data *data)
{
	t_tile_kind_color const	tile_kind_data_color = {
		.initial_color = {PLAYER_2_R, PLAYER_2_G, PLAYER_2_B},
		.min_color = {PLAYER_2_MIN_R, PLAYER_2_MIN_G, PLAYER_2_MIN_B},
		.max_color = {PLAYER_2_MAX_R, PLAYER_2_MAX_G, PLAYER_2_MAX_B},
		.wait = {PLAYER_2_R_WAIT, PLAYER_2_G_WAIT, PLAYER_2_B_WAIT},
		.step = {PLAYER_2_R_STEP, PLAYER_2_G_STEP, PLAYER_2_B_STEP}
	};

	if (sanitize_tile_kind(tile_kind_data_color, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
