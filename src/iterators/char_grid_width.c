/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid_width.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:57:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/26 17:51:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_char_grid_width(t_data *data,
								bool reset)
{
	static t_iterator	it;

	if (!it.initialized || reset)
	{
		it = ft_get_range_start_0_iterator(data->char_grid.width);
		it.initialized = true;
		data->it.column_index = 0;
	}
	if (reset)
		return (RESET);
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
