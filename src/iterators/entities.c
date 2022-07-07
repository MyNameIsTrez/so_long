/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entities.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 15:41:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/07 16:01:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_entities(t_data *data)
{
	while (data->t.it.entities != NULL)
	{
		data->t.entity = data->t.it.entities->content;
		data->t.it.entities = data->t.it.entities->next;
		return (LOOPED);
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_reset_iterate_entities(t_data *data)
{
	data->t.it.entities = data->entities;
}

////////////////////////////////////////////////////////////////////////////////
