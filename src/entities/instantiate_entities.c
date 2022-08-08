/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_entities.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:00:50 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 12:32:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/instantiate_entities/sl_private_instantiate_entities.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_entities(t_data *data)
{
	t_it_char_grid	it;

	sl_init_it_char_grid(&it);
	data->entities = ft_vector_new(sizeof(t_entity));
	while (sl_iterate_char_grid(&it, data) != FINISHED)
		if (sl_is_entity(data))
			if (instantiate_entity(data) != OK)
				return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
