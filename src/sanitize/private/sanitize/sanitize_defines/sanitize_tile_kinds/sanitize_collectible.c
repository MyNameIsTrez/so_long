/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_collectible.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:53:57 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 15:26:23 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_private_sanitize_defines.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_collectible(t_data *data)
{
	const t_tile_kind_data_color	tile_kind_data_color = {
		.initial_color = {COLLECTIBLE_R, COLLECTIBLE_G, COLLECTIBLE_B},
		.min_color_offset = {COLLECTIBLE_MIN_R_OFFSET, COLLECTIBLE_MIN_G_OFFSET,
		COLLECTIBLE_MIN_B_OFFSET},
		.max_color_offset = {COLLECTIBLE_MAX_R_OFFSET, COLLECTIBLE_MAX_G_OFFSET,
		COLLECTIBLE_MAX_B_OFFSET},
		.wait = {COLLECTIBLE_R_WAIT, COLLECTIBLE_G_WAIT, COLLECTIBLE_B_WAIT},
		.step = {COLLECTIBLE_R_STEP, COLLECTIBLE_G_STEP, COLLECTIBLE_B_STEP}
	};

	if (sanitize_tile_kind(tile_kind_data_color, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
