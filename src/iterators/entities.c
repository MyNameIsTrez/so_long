/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entities.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 15:41:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 20:46:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_entities(t_data *data,
								bool reset)
{
	static t_iterator	it;

	if (reset)
	{
		it.initialized = false;
		data->it.entity = NULL;
		return (RESET);
	}
	if (!it.initialized)
		it = ft_get_vector_iterator(data->entities);
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.entity = (t_entity *)it.current;
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
