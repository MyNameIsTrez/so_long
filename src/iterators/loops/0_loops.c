/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_loops.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/30 15:02:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/05 14:07:10 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_loop_status	sl_loop_char_grid_width(uint32_t *column_index_ptr,
			t_data *data, bool reset)
{
	static uint32_t	column_index = 0;

	if (reset)
	{
		column_index = 0;
		return (RESET);
	}
	while (column_index < data->char_grid.width)
	{
		*column_index_ptr = column_index;
		column_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

t_loop_status	sl_loop_char_grid_height(uint32_t *row_index_ptr, t_data *data,
			bool reset)
{
	static uint32_t	row_index = 0;

	if (reset)
	{
		row_index = 0;
		return (RESET);
	}
	while (row_index < data->char_grid.height)
	{
		*row_index_ptr = row_index;
		row_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

t_loop_status	sl_loop_char_grid(uint32_t *column_index_ptr,
			uint32_t *row_index_ptr, t_data *data, bool reset)
{
	static uint32_t	column_index = 0;
	static uint32_t	row_index = 0;

	if (reset)
	{
		sl_loop_char_grid_height(NULL, NULL, true);
		sl_loop_char_grid_width(NULL, NULL, true);
		column_index = 0;
		row_index = 0;
		return (RESET);
	}
	while (true)
	{
		*row_index_ptr = row_index;
		while (true)
		{
			*column_index_ptr = column_index;
			if (sl_loop_char_grid_width(&column_index, data, false) != 1)
				break ;
			return (LOOPED);
		}
		sl_loop_char_grid_width(NULL, NULL, true);
		if (sl_loop_char_grid_height(&row_index, data, false) != 1)
			break ;
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
