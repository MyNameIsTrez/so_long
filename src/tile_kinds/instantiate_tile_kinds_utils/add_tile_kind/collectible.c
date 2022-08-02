/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:05:52 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/02 15:22:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../sl_instantiate_tile_kinds_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_collectible_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			COLLECTIBLE_TEXTURE_FRAME_COUNT,
			COLLECTIBLE_TEXTURE_ROW,
			COLLECTIBLE_CHARACTER,
			COLLECTIBLE_DEPTH,
			(t_tile_kind_color){
			{COLLECTIBLE_R, COLLECTIBLE_G, COLLECTIBLE_B},
			{COLLECTIBLE_MIN_R_OFFSET, COLLECTIBLE_MIN_G_OFFSET,
				COLLECTIBLE_MIN_B_OFFSET},
			{COLLECTIBLE_MAX_R_OFFSET, COLLECTIBLE_MAX_G_OFFSET,
				COLLECTIBLE_MAX_B_OFFSET},
			{COLLECTIBLE_R_WAIT, COLLECTIBLE_G_WAIT, COLLECTIBLE_B_WAIT},
			{COLLECTIBLE_R_STEP, COLLECTIBLE_G_STEP, COLLECTIBLE_B_STEP}}},
			data) != OK)
		return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
