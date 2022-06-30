/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_iterators.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/30 14:42:15 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_loop_status	loop_width(uint32_t *column_index_res, t_data *data,
			bool reset)
{
	static uint32_t	column_index = 0;

	if (reset)
	{
		column_index = 0;
		return (RESET);
	}
	while (column_index < data->char_grid.width)
	{
		*column_index_res = column_index;
		column_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

STATIC t_loop_status	loop_height(uint32_t *row_index_res, t_data *data,
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
		*row_index_res = row_index;
		row_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

STATIC t_loop_status	loop_char_grid(uint32_t *column_index_res,
			uint32_t *row_index_res, t_data *data, bool reset)
{
	static uint32_t	column_index = 0;
	static uint32_t	row_index = 0;

	if (reset)
	{
		loop_height(NULL, NULL, true);
		loop_width(NULL, NULL, true);
		column_index = 0;
		row_index = 0;
		return (RESET);
	}
	while (true)
	{
		*row_index_res = row_index;
		while (true)
		{
			*column_index_res = column_index;
			if (loop_width(&column_index, data, false) != 1)
				break ;
			return (LOOPED);
		}
		loop_width(NULL, NULL, true);
		if (loop_height(&row_index, data, false) != 1)
			break ;
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_iterate_char_grid(t_iterator_callback_char_grid callback,
			t_data *data)
{
	uint32_t	column_index;
	uint32_t	row_index;

	loop_char_grid(NULL, NULL, NULL, true);
	while (loop_char_grid(&column_index, &row_index, data,
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
