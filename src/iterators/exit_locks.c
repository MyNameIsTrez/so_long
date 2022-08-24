/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_locks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 16:20:10 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 12:55:03 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_exit_locks(t_iterator *it, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_vector_iterator(data->exit_locks);
	if (ft_iterate(it) != FINISHED)
	{
		data->it.exit_lock = (t_exit_lock *)it->current;
		return (LOOPED);
	}
	data->it.exit_lock = (t_exit_lock *)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
