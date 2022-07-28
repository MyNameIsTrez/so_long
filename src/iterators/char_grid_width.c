/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid_width.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:57:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/28 10:54:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_char_grid_width(t_data *data,
								bool reset)
{
	static t_iterator	it;

	if (!it.initialized)
		it = ft_get_range_start_0_iterator(data->char_grid.width);
	if (reset)
	{
		it.initialized = false;
		data->it.column_index = 0;
		return (RESET);
	}
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.column_index = (t_i32)it.current;
		return (LOOPED);
	}
	sl_reset_iterate_char_grid_width(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid_width(t_data *data)
{
	return (resettable_iterate_char_grid_width(data, false));
}

void	sl_reset_iterate_char_grid_width(t_data *data)
{
	resettable_iterate_char_grid_width(data, true);
}

////////////////////////////////////////////////////////////////////////////////
