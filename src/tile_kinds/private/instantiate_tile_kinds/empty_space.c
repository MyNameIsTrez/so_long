/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_space.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:06:39 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 18:04:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_thing_tile_kind/sl_private_add_thing_tile_kind.h"
#include "add_thing_tile_kind/add_tile_kind/sl_private_tile_kind_data.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_empty_space_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			EMPTY_SPACE_TEXTURE_FRAME_COUNT,
			EMPTY_SPACE_TEXTURE_ROW,
			EMPTY_SPACE_CHARACTER,
			EMPTY_SPACE_IS_ENTITY,
			EMPTY_SPACE_DEPTH,
			EMPTY_SPACE_TICKS_BETWEEN_FRAME_CHANGES,
			EMPTY_SPACE_TICKS_BETWEEN_UPDATES,
			(t_tile_kind_data_color){
			{EMPTY_SPACE_R, EMPTY_SPACE_G, EMPTY_SPACE_B},
			{EMPTY_SPACE_MIN_R, EMPTY_SPACE_MIN_G, EMPTY_SPACE_MIN_B},
			{EMPTY_SPACE_MAX_R, EMPTY_SPACE_MAX_G, EMPTY_SPACE_MAX_B},
			{EMPTY_SPACE_R_WAIT, EMPTY_SPACE_G_WAIT, EMPTY_SPACE_B_WAIT},
			{EMPTY_SPACE_R_STEP, EMPTY_SPACE_G_STEP, EMPTY_SPACE_B_STEP}}},
			data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
