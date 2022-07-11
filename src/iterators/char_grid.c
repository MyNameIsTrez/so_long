/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:55:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/11 14:42:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_char_grid(t_data *data,
			bool reset)
{
	if (reset)
	{
		sl_reset_iterate_char_grid_height(data);
		sl_reset_iterate_char_grid_width(data);
		return (RESET);
	}
	while (true)
	{
		while (true)
		{
			if (sl_iterate_char_grid_width(data) != LOOPED)
				break ;
			return (LOOPED);
		}
		sl_reset_iterate_char_grid_width(data);
		if (data->t.row_index == 0)
			sl_iterate_char_grid_height(data);
		if (sl_iterate_char_grid_height(data) != LOOPED)
			break ;
	}
	sl_reset_iterate_char_grid(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid(t_data *data)
{
	return (resettable_iterate_char_grid(data, false));
}

void	sl_reset_iterate_char_grid(t_data *data)
{
	resettable_iterate_char_grid(data, true);
}

////////////////////////////////////////////////////////////////////////////////
