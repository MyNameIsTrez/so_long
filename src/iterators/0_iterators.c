/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_iterators.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/30 16:18:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_iterate_char_grid_height(
			t_iterator_callback_char_grid_height callback, t_data *data)
{
	uint32_t	row_index;

	sl_loop_char_grid_height(NULL, NULL, true);
	while (sl_loop_char_grid_height(&row_index, data, false) != FINISHED)
	{
		if (callback(row_index, data) != OK)
		{
			return (ft_get_error());
		}
	}
	return (OK);
}

t_status	sl_iterate_char_grid(t_iterator_callback_char_grid callback,
			t_data *data)
{
	uint32_t	column_index;
	uint32_t	row_index;

	sl_loop_char_grid(NULL, NULL, NULL, true);
	while (sl_loop_char_grid(&column_index, &row_index, data,
			false) != FINISHED)
	{
		if (callback(column_index, row_index, data) != OK)
		{
			return (ft_get_error());
		}
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
