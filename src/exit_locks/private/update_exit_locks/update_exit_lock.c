/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_exit_lock.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 13:22:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 14:24:42 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_exit_lock(t_exit_lock *exit_lock, t_data *data)
{
	(void)data;
	if (exit_lock->entity->tile.frame_index == exit_lock->entity->tile.tile_kind->frame_count - 1)
	{
		exit_lock->entity->enabled = false; // TODO: Rename enabled here to animated
		sl_hide_and_disable_entity(exit_lock->entity);
	}
}

////////////////////////////////////////////////////////////////////////////////
