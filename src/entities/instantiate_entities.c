/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_entities.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:00:50 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/04 13:35:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "instantiate_entities_utils/sl_instantiate_entities_utils.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_entities(t_data *data)
{
	data->entities = ft_vector_new(sizeof(t_entity));
	while (sl_iterate_char_grid(data) != FINISHED)
		if (sl_is_entity(data))
			if (instantiate_entity(data) != OK)
				return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
