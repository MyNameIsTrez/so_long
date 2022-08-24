/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_exit_locks.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 11:58:05 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 13:04:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/instantiate_exit_locks/sl_private_instantiate_exit_locks.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_exit_locks(t_data *data)
{
	t_iterator	it;
	t_u8		character;

	data->exit_locks = ft_vector_new(sizeof(t_exit_lock));
	ft_init_it(&it);
	while (sl_iterate_entities(&it, data) != FINISHED)
	{
		character = data->it.entity->tile.tile_kind->character;
		if (character == EXIT_LOCK_CHARACTER)
			if (instantiate_exit_lock(data) != OK)
				return (ERROR);
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
