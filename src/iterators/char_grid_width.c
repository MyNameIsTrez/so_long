/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid_width.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:57:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/07 15:02:23 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid_width(t_data *data)
{
	while (data->t.it.column_index < data->char_grid.width)
	{
		data->t.column_index = data->t.it.column_index;
		data->t.it.column_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_reset_iterate_char_grid_width(t_data *data)
{
	data->t.it.column_index = 0;
}

////////////////////////////////////////////////////////////////////////////////
