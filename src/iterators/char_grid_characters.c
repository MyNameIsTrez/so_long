/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid_characters.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:55:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/17 16:34:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid_characters(t_iterator *it,
						t_data *data)
{
	if (!it->initialized)
		*it = ft_get_count_iterator(
				data->char_grid.width * data->char_grid.height);
	if (ft_iterate(it) != FINISHED)
	{
		data->it.char_grid_character = \
			data->char_grid.cells[(size_t)it->current];
		return (LOOPED);
	}
	data->it.char_grid_character = data->char_grid.cells[(size_t)it->current];
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
