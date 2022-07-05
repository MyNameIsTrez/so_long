/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_iterators.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/05 16:31:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid_width(t_data *data, bool reset)
{
	static uint32_t	column_index;

	if (reset)
	{
		column_index = 0;
		return (RESET);
	}
	while (column_index < data->t.char_grid.width)
	{
		data->t.column_index = column_index;
		column_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

t_iterator_status	sl_iterate_char_grid_height(t_data *data, bool reset)
{
	static uint32_t	row_index;

	if (reset)
	{
		row_index = 0;
		return (RESET);
	}
	while (row_index < data->t.char_grid.height)
	{
		data->t.row_index = row_index;
		row_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

t_iterator_status	sl_iterate_char_grid(t_data *data, bool reset)
{
	if (reset)
	{
		sl_iterate_char_grid_height(data, true);
		sl_iterate_char_grid_width(data, true);
		return (RESET);
	}
	while (true)
	{
		while (true)
		{
			if (sl_iterate_char_grid_width(data, false) != LOOPED)
				break ;
			return (LOOPED);
		}
		sl_iterate_char_grid_width(data, true);
		if (sl_iterate_char_grid_height(data, false) != LOOPED)
			break ;
	}
	return (FINISHED);
}

t_iterator_status	sl_iterate_frame_count(uint32_t frame_count, t_data *data,
			bool reset)
{
	static uint32_t	frame_index = 0;

	if (reset)
	{
		frame_index = 0;
		return (RESET);
	}
	while (frame_index < frame_count)
	{
		data->t.frame_index = frame_index;
		frame_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
