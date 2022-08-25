/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_exit_locks.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 13:19:26 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 13:21:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/update_exit_locks/sl_private_update_exit_locks.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_exit_locks(t_data *data)
{
	t_iterator	it;
	t_exit_lock	*exit_lock;
	t_entity	*entity;

	ft_init_it(&it);
	while (sl_iterate_exit_locks(&it, data) != FINISHED)
	{
		exit_lock = data->it.exit_lock;
		entity = exit_lock->entity;
		if (entity->ticks_since_last_update > \
			entity->ticks_between_updates)
		{
			sl_update_exit_lock(exit_lock, data);
			entity->ticks_since_last_update = 0;
		}
		else
			entity->ticks_since_last_update++;
	}
}

////////////////////////////////////////////////////////////////////////////////
