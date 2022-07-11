/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid_width.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:57:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/11 14:25:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_char_grid_width(t_data *data,
			bool reset)
{
	static uint32_t	column_index;

	if (reset)
	{
		column_index = 0;
		return (RESET);
	}
	while (column_index < data->char_grid.width)
	{
		data->t.column_index = column_index;
		column_index++;
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
