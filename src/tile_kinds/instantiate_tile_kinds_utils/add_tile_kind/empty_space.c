/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_empty_space_tile_kind.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:06:39 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:06:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_instantiate_tile_kinds_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_empty_space_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			EMPTY_SPACE_TEXTURE_FRAME_COUNT,
			EMPTY_SPACE_TEXTURE_ROW,
			EMPTY_SPACE_CHARACTER,
			EMPTY_SPACE_DEPTH,
			(t_tile_kind_color){
			{EMPTY_SPACE_R, EMPTY_SPACE_G, EMPTY_SPACE_B},
			{EMPTY_SPACE_MIN_R, EMPTY_SPACE_MIN_G, EMPTY_SPACE_MIN_B},
			{EMPTY_SPACE_MAX_R, EMPTY_SPACE_MAX_G, EMPTY_SPACE_MAX_B},
			{EMPTY_SPACE_R_WAIT, EMPTY_SPACE_G_WAIT, EMPTY_SPACE_B_WAIT},
			{EMPTY_SPACE_R_STEP, EMPTY_SPACE_G_STEP, EMPTY_SPACE_B_STEP}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
