/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entities.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 15:41:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_entities(t_data *data,
								bool reset)
{
	static size_t	entity_index;

	if (reset)
	{
		entity_index = 0;
		return (RESET);
	}
	while (entity_index < ft_vector_get_size(data->entities))
	{
		data->it.entity = &data->entities[entity_index];
		entity_index++;
		return (LOOPED);
	}
	sl_reset_iterate_entities(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_entities(t_data *data)
{
	return (resettable_iterate_entities(data, false));
}

void	sl_reset_iterate_entities(t_data *data)
{
	resettable_iterate_entities(data, true);
}

////////////////////////////////////////////////////////////////////////////////
