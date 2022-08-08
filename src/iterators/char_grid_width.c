/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid_width.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:57:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 14:14:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid_width(t_iterator *it, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_count_iterator(data->char_grid.width);
	while (ft_iterate(it) != FINISHED)
	{
		data->it.column_index = (size_t)it->current;
		return (LOOPED);
	}
	data->it.column_index = (size_t)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
