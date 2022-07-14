/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entities.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 15:41:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 11:58:05 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_entities(t_data *data,
			bool reset)
{
	static t_list	*entities;

	if (reset)
	{
		entities = data->entities;
		data->it.entity = NULL;
		return (RESET);
	}
	while (entities != NULL)
	{
		data->it.entity = entities->content;
		entities = entities->next;
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
