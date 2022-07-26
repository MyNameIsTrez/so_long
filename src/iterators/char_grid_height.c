/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid_height.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:59:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/26 17:47:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_char_grid_height(t_data *data,
								bool reset)
{
	static t_iterator	it;

	if (!it.initialized || reset)
	{
		it = ft_get_range_start_0_iterator(data->char_grid.height);
		it.initialized = true;
		data->it.row_index = 0;
	}
	if (reset)
		return (RESET);
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.row_index = (t_i32)it.current;
		return (LOOPED);
	}
	sl_reset_iterate_char_grid_height(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid_height(t_data *data)
{
	return (resettable_iterate_char_grid_height(data, false));
}

void	sl_reset_iterate_char_grid_height(t_data *data)
{
	resettable_iterate_char_grid_height(data, true);
}

////////////////////////////////////////////////////////////////////////////////
