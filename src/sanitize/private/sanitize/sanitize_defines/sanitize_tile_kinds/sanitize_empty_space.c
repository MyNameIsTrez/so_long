/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_empty_space.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 14:53:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 11:27:33 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "sanitize_thing_tile_kind/sl_private_sanitize_thing_tile_kind.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_empty_space(t_data *data)
{
	const t_tile_kind_data_color	tile_kind_data_color = {
		.initial_color = {EMPTY_SPACE_R, EMPTY_SPACE_G, EMPTY_SPACE_B},
		.min_color = {EMPTY_SPACE_MIN_R, EMPTY_SPACE_MIN_G, EMPTY_SPACE_MIN_B},
		.max_color = {EMPTY_SPACE_MAX_R, EMPTY_SPACE_MAX_G, EMPTY_SPACE_MAX_B},
		.wait = {EMPTY_SPACE_R_WAIT, EMPTY_SPACE_G_WAIT, EMPTY_SPACE_B_WAIT},
		.step = {EMPTY_SPACE_R_STEP, EMPTY_SPACE_G_STEP, EMPTY_SPACE_B_STEP}
	};

	if (sanitize_tile_kind(tile_kind_data_color, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
