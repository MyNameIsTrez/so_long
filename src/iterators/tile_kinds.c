/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tile_kinds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 17:54:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 19:06:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_tile_kinds(t_iterator *it, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_vector_iterator(data->tile_kinds);
	if (ft_iterate(it) != FINISHED)
	{
		data->it.tile_kind = (t_tile_kind *)it->current;
		return (LOOPED);
	}
	data->it.tile_kind = (t_tile_kind *)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
