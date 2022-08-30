/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_lock.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:05:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 18:04:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_thing_tile_kind/sl_private_add_thing_tile_kind.h"
#include "add_thing_tile_kind/add_tile_kind/sl_private_tile_kind_data.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_exit_lock_tile_kind(t_data *data)
{
	t_tile_kind_data const	tk_data = {
		.character = EXIT_LOCK_CHARACTER,
		.is_entity = EXIT_LOCK_IS_ENTITY,
		.frame_count = EXIT_LOCK_TEXTURE_FRAME_COUNT,
		.texture_row = EXIT_LOCK_TEXTURE_ROW,
		.depth = EXIT_LOCK_DEPTH,
		.ticks_between_frame_changes = EXIT_LOCK_TICKS_BETWEEN_FRAME_CHANGES,
		.ticks_between_updates = EXIT_LOCK_TICKS_BETWEEN_UPDATES,
		(t_tile_kind_color){
	{EXIT_LOCK_R, EXIT_LOCK_G, EXIT_LOCK_B},
	{EXIT_LOCK_MIN_R, EXIT_LOCK_MIN_G, EXIT_LOCK_MIN_B},
	{EXIT_LOCK_MAX_R, EXIT_LOCK_MAX_G, EXIT_LOCK_MAX_B},
	{EXIT_LOCK_R_WAIT, EXIT_LOCK_G_WAIT, EXIT_LOCK_B_WAIT},
	{EXIT_LOCK_R_STEP, EXIT_LOCK_G_STEP, EXIT_LOCK_B_STEP}}};

	if (add_tile_kind(tk_data, data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
