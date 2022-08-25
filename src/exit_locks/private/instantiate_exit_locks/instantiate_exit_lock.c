/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_exit_lock.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 11:57:54 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 15:59:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	instantiate_exit_lock(t_data *data)
{
	t_exit_lock	exit_lock;

	exit_lock.entity = data->it.entity;
	exit_lock.entity->animated = false;
	if (ft_vector_push(&data->exit_locks, &exit_lock) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
