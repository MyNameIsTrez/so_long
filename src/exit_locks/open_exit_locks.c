/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_exit_locks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 12:07:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 15:59:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_open_exit_locks(t_data *data)
{
	t_iterator	it;

	ft_init_it(&it);
	while (sl_iterate_exit_locks(&it, data) != FINISHED)
		data->it.exit_lock->entity->animated = true;
}

////////////////////////////////////////////////////////////////////////////////
