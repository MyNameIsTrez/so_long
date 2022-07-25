/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entities.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 15:41:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/25 16:41:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_entities(t_data *data,
								bool reset)
{
	static t_i32	entity_index;

	if (reset)
	{
		entity_index = 0;
		data->it.entity = NULL;
		return (RESET);
	}
	while (entity_index < data->entity_count)
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
