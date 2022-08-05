/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_tile.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:06:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 17:57:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_thing_tile_kind/sl_private_add_thing_tile_kind.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_wall_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			WALL_TEXTURE_FRAME_COUNT,
			WALL_TEXTURE_ROW,
			WALL_CHARACTER,
			WALL_DEPTH,
			(t_tile_kind_data_color){
			{WALL_R, WALL_G, WALL_B},
			{WALL_MIN_R_OFFSET, WALL_MIN_G_OFFSET,
				WALL_MIN_B_OFFSET},
			{WALL_MAX_R_OFFSET, WALL_MAX_G_OFFSET,
				WALL_MAX_B_OFFSET},
			{WALL_R_WAIT, WALL_G_WAIT, WALL_B_WAIT},
			{WALL_R_STEP, WALL_G_STEP, WALL_B_STEP}}},
			data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
