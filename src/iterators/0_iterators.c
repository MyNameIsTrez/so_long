/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_iterators.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/29 17:11:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "iterators.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_char_grid_width(uint32_t row_index,
			t_char_grid_iterate_callback callback, t_data *data)
{
	uint32_t	column_index;

	column_index = 0;
	while (column_index < data->char_grid.width)
	{
		if (callback(column_index, row_index, data) != OK)
			return (ft_get_error());
		column_index++;
	}
	return (OK);
}

// t_status	sl_char_grid_height(t_char_grid_iterate_callback callback,
// 			t_data *data)
// {
// 	uint32_t	row_index;

// 	row_index = 0;
// 	while (row_index < data->char_grid.height)
// 	{
// 		if (callback(row_index, callback, data) != OK)
// 			return (ft_get_error());
// 		row_index++;
// 	}
// 	return (OK);
// }

t_status	sl_char_grid_iterate(t_char_grid_iterate_callback callback,
			t_data *data)
{
	uint32_t	row_index;

	row_index = 0;
	while (row_index < data->char_grid.height)
	{
		if (sl_char_grid_width(row_index, callback, data) != OK)
			return (ft_get_error());
		row_index++;
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

// int	sl_width(uint32_t *column_index_res, t_data *data, bool reset)
// {
// 	static uint32_t	column_index = 0;

// 	if (reset)
// 	{
// 		column_index = 0;
// 		return (0);
// 	}
// 	while (column_index < data->char_grid.width)
// 	{
// 		*column_index_res = column_index;
// 		column_index++;
// 		return (1);
// 	}
// 	return (-1);
// }

// int	sl_height(uint32_t *row_index_res, t_data *data, bool reset)
// {
// 	static uint32_t	row_index = 0;

// 	if (reset)
// 	{
// 		row_index = 0;
// 		return (0);
// 	}
// 	while (row_index < data->char_grid.width)
// 	{
// 		*row_index_res = row_index;
// 		row_index++;
// 		return (1);
// 	}
// 	return (-1);
// }

// int	sl_char_grid_iterate2(uint32_t *column_index_res, uint32_t *row_index_res,
// 			t_data *data, bool reset)
// {
// 	static uint32_t	column_index = 0;
// 	static uint32_t	row_index = 0;

// 	if (reset)
// 	{
// 		sl_height(NULL, NULL, true);
// 		sl_width(NULL, NULL, true);
// 		column_index = 0;
// 		row_index = 0;
// 		return (0);
// 	}
// 	while (sl_height(&row_index, data, false) == 1)
// 	{
// 		*row_index_res = row_index;
// 		while (sl_width(&column_index, data, false) == 1)
// 		{
// 			*column_index_res = column_index;
// 			return (1);
// 		}
// 		sl_width(NULL, NULL, true);
// 	}
// 	return (-1);
// }

////////////////////////////////////////////////////////////////////////////////
