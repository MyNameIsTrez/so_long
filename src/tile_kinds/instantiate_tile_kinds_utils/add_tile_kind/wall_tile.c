/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_wall_tile_kind.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:06:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:06:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_instantiate_tile_kinds_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_wall_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			WALL_TEXTURE_FRAME_COUNT,
			WALL_TEXTURE_ROW,
			WALL_CHARACTER,
			WALL_DEPTH,
			(t_tile_kind_color){
			{WALL_R, WALL_G, WALL_B},
			{WALL_MIN_R, WALL_MIN_G, WALL_MIN_B},
			{WALL_MAX_R, WALL_MAX_G, WALL_MAX_B},
			{WALL_R_WAIT, WALL_G_WAIT, WALL_B_WAIT},
			{WALL_R_STEP, WALL_G_STEP, WALL_B_STEP}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////