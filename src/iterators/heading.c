/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:57:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 16:15:56 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_heading(t_iterator *it, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_count_iterator(4);
	while (ft_iterate(it) != FINISHED)
	{
		data->it.heading = (t_heading)it->current;
		return (LOOPED);
	}
	data->it.heading = (t_heading)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
