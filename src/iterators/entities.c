/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entities.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 15:41:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 19:57:30 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_entities(t_iterator *it, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_vector_iterator(data->entities);
	while (ft_iterate(it) != FINISHED)
	{
		data->it.entity = (t_entity *)it->current;
		return (LOOPED);
	}
	it->initialized = false;
	data->it.entity = NULL;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
