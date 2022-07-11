/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid_height.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:59:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/11 14:53:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_char_grid_height(t_data *data,
			bool reset)
{
	static uint32_t	row_index;

	if (reset)
	{
		row_index = 0;
		data->t.row_index = 0;
		return (RESET);
	}
	while (row_index < data->char_grid.height)
	{
		data->t.row_index = row_index;
		row_index++;
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
