/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monster.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 15:00:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/04 15:00:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_instantiate_tile_kinds_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_monster_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			MONSTER_TEXTURE_FRAME_COUNT,
			MONSTER_TEXTURE_ROW,
			MONSTER_CHARACTER,
			MONSTER_DEPTH,
			(t_tile_kind_data_color){
			{MONSTER_R, MONSTER_G, MONSTER_B},
			{MONSTER_MIN_R_OFFSET, MONSTER_MIN_G_OFFSET,
				MONSTER_MIN_B_OFFSET},
			{MONSTER_MAX_R_OFFSET, MONSTER_MAX_G_OFFSET,
				MONSTER_MAX_B_OFFSET},
			{MONSTER_R_WAIT, MONSTER_G_WAIT, MONSTER_B_WAIT},
			{MONSTER_R_STEP, MONSTER_G_STEP, MONSTER_B_STEP}}},
			data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
