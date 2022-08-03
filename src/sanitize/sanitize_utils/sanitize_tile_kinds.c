/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sanitize_tile_kinds.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 16:47:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 14:33:21 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_min_color_offset(
				t_tile_kind_data_color tile_kind_data_color, t_data *data)
{
	size_t	channel;

	while (sl_iterate_rgb_channel_indices(data) != FINISHED)
	{
		channel = data->it.rgb_channel_index;
		if (tile_kind_data_color.initial_color[channel] - \
			tile_kind_data_color.min_color_offset[channel] < 0)
			return (sl_set_error(SL_ERROR_TOO_LOW_MIN_COLOR));
	}
	return (OK);
}

t_status	sanitize_max_color_offset(
				t_tile_kind_data_color tile_kind_data_color, t_data *data)
{
	size_t	channel;

	while (sl_iterate_rgb_channel_indices(data) != FINISHED)
	{
		channel = data->it.rgb_channel_index;
		if (tile_kind_data_color.initial_color[channel] + \
			tile_kind_data_color.max_color_offset[channel] > 255)
			return (sl_set_error(SL_ERROR_TOO_HIGH_MAX_COLOR));
	}
	return (OK);
}

t_status	sanitize_tile_kind(t_tile_kind_data_color tile_kind_data_color,
				t_data *data)
{
	if (sanitize_min_color_offset(tile_kind_data_color, data) || \
		sanitize_max_color_offset(tile_kind_data_color, data))
		return (sl_any_error());
	return (OK);
}

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
		return (sl_any_error());
	return (OK);
}

t_status	sanitize_empty_space(t_data *data)
{
	const t_tile_kind_data_color	tile_kind_data_color = {
		.initial_color = {EMPTY_SPACE_R, EMPTY_SPACE_G, EMPTY_SPACE_B},
		.min_color_offset = {EMPTY_SPACE_MIN_R_OFFSET, EMPTY_SPACE_MIN_G_OFFSET,
		EMPTY_SPACE_MIN_B_OFFSET},
		.max_color_offset = {EMPTY_SPACE_MAX_R_OFFSET, EMPTY_SPACE_MAX_G_OFFSET,
		EMPTY_SPACE_MAX_B_OFFSET},
		.wait = {EMPTY_SPACE_R_WAIT, EMPTY_SPACE_G_WAIT, EMPTY_SPACE_B_WAIT},
		.step = {EMPTY_SPACE_R_STEP, EMPTY_SPACE_G_STEP, EMPTY_SPACE_B_STEP}
	};

	if (sanitize_tile_kind(tile_kind_data_color, data) != OK)
		return (sl_any_error());
	return (OK);
}

t_status	sanitize_map_exit(t_data *data)
{
	const t_tile_kind_data_color	tile_kind_data_color = {
		.initial_color = {MAP_EXIT_R, MAP_EXIT_G, MAP_EXIT_B},
		.min_color_offset = {MAP_EXIT_MIN_R_OFFSET, MAP_EXIT_MIN_G_OFFSET,
		MAP_EXIT_MIN_B_OFFSET},
		.max_color_offset = {MAP_EXIT_MAX_R_OFFSET, MAP_EXIT_MAX_G_OFFSET,
		MAP_EXIT_MAX_B_OFFSET},
		.wait = {MAP_EXIT_R_WAIT, MAP_EXIT_G_WAIT, MAP_EXIT_B_WAIT},
		.step = {MAP_EXIT_R_STEP, MAP_EXIT_G_STEP, MAP_EXIT_B_STEP}
	};

	if (sanitize_tile_kind(tile_kind_data_color, data) != OK)
		return (sl_any_error());
	return (OK);
}

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

t_status	sanitize_wall(t_data *data)
{
	const t_tile_kind_data_color	tile_kind_data_color = {
		.initial_color = {WALL_R, WALL_G, WALL_B},
		.min_color_offset = {WALL_MIN_R_OFFSET, WALL_MIN_G_OFFSET,
		WALL_MIN_B_OFFSET},
		.max_color_offset = {WALL_MAX_R_OFFSET, WALL_MAX_G_OFFSET,
		WALL_MAX_B_OFFSET},
		.wait = {WALL_R_WAIT, WALL_G_WAIT, WALL_B_WAIT},
		.step = {WALL_R_STEP, WALL_G_STEP, WALL_B_STEP}
	};

	if (sanitize_tile_kind(tile_kind_data_color, data) != OK)
		return (sl_any_error());
	return (OK);
}

t_status	sanitize_tile_kinds(t_data *data)
{
	if (sanitize_collectible(data) != OK || \
		sanitize_empty_space(data) != OK || \
		sanitize_map_exit(data) != OK || \
		sanitize_player(data) != OK || \
		sanitize_wall(data) != OK)
		return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
