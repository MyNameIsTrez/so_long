/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:57:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 19:09:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_heading(t_data *data, bool reset)
{
	static t_iterator	it;

	if (reset)
	{
		it.initialized = false;
		data->it.heading = HEADING_NONE;
		return (RESET);
	}
	if (!it.initialized)
		it = ft_get_count_iterator(4);
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.heading = (t_heading)it.current;
		return (LOOPED);
	}
	sl_reset_iterate_heading(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_heading(t_data *data)
{
	return (resettable_iterate_heading(data, false));
}

void	sl_reset_iterate_heading(t_data *data)
{
	resettable_iterate_heading(data, true);
}

////////////////////////////////////////////////////////////////////////////////