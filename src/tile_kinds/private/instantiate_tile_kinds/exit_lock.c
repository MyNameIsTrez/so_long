/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_lock.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:05:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 16:29:18 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_thing_tile_kind/sl_private_add_thing_tile_kind.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_exit_lock_tile_kind(t_data *data)
{
	if (add_tile_kind((t_tile_kind_data){
			EXIT_LOCK_TEXTURE_FRAME_COUNT,
			EXIT_LOCK_TEXTURE_ROW,
			EXIT_LOCK_CHARACTER,
			EXIT_LOCK_IS_ENTITY,
			EXIT_LOCK_DEPTH,
			(t_tile_kind_data_color){
			{EXIT_LOCK_R, EXIT_LOCK_G, EXIT_LOCK_B},
			{EXIT_LOCK_MIN_R, EXIT_LOCK_MIN_G, EXIT_LOCK_MIN_B},
			{EXIT_LOCK_MAX_R, EXIT_LOCK_MAX_G, EXIT_LOCK_MAX_B},
			{EXIT_LOCK_R_WAIT, EXIT_LOCK_G_WAIT, EXIT_LOCK_B_WAIT},
			{EXIT_LOCK_R_STEP, EXIT_LOCK_G_STEP, EXIT_LOCK_B_STEP}}},
			data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
