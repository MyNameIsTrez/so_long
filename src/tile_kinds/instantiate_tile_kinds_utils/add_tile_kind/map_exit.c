/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_map_exit_tile_kind.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:05:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:05:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_instantiate_tile_kinds_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_map_exit_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			MAP_EXIT_TEXTURE_FRAME_COUNT,
			MAP_EXIT_TEXTURE_ROW,
			MAP_EXIT_CHARACTER,
			MAP_EXIT_DEPTH,
			(t_tile_kind_color){
			{MAP_EXIT_R, MAP_EXIT_G, MAP_EXIT_B},
			{MAP_EXIT_MIN_R, MAP_EXIT_MIN_G, MAP_EXIT_MIN_B},
			{MAP_EXIT_MAX_R, MAP_EXIT_MAX_G, MAP_EXIT_MAX_B},
			{MAP_EXIT_R_WAIT, MAP_EXIT_G_WAIT, MAP_EXIT_B_WAIT},
			{MAP_EXIT_R_STEP, MAP_EXIT_G_STEP, MAP_EXIT_B_STEP}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
