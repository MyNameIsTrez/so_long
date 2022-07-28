/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid_height.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:59:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/28 14:41:34 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_char_grid_height(t_data *data,
								bool reset)
{
	static t_iterator	it;

	if (reset)
	{
		it.initialized = false;
		data->it.row_index = 0;
		return (RESET);
	}
	if (!it.initialized)
		it = ft_get_count_iterator(data->char_grid.height);
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.row_index = (size_t)it.current;
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
