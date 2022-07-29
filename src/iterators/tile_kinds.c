/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tile_kinds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 17:54:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 21:18:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_tile_kinds(t_data *data,
								bool reset)
{
	static t_iterator	it;

	if (reset)
	{
		it.initialized = false;
		// data->it.tile_kind = NULL; // TODO: Get this in here without having the program crash
		return (RESET);
	}
	if (!it.initialized)
		it = ft_get_vector_iterator(data->tile_kinds);
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.tile_kind = (t_tile_kind *)it.current;
		return (LOOPED);
	}
	sl_reset_iterate_tile_kinds(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_tile_kinds(t_data *data)
{
	return (resettable_iterate_tile_kinds(data, false));
}

void	sl_reset_iterate_tile_kinds(t_data *data)
{
	resettable_iterate_tile_kinds(data, true);
}

////////////////////////////////////////////////////////////////////////////////
