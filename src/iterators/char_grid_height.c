/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid_height.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:59:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/07 15:02:23 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid_height(t_data *data)
{
	while (data->t.it.row_index < data->char_grid.height)
	{
		data->t.row_index = data->t.it.row_index;
		data->t.it.row_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_reset_iterate_char_grid_height(t_data *data)
{
	data->t.it.row_index = 0;
}

////////////////////////////////////////////////////////////////////////////////
