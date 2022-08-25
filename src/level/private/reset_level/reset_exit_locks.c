/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_exit_locks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 16:52:39 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 16:59:22 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	reset_exit_locks(t_data *data)
{
	t_iterator	it;
	t_exit_lock	*exit_lock;

	ft_init_it(&it);
	while (sl_iterate_exit_locks(&it, data) != FINISHED)
	{
		exit_lock = data->it.exit_lock;
		sl_change_frame(&exit_lock->entity->tile, 0);
	}
}

////////////////////////////////////////////////////////////////////////////////
