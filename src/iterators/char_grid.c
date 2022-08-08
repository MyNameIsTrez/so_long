/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:55:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 14:55:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid(t_it_char_grid *it, t_data *data)
{
	while (true)
	{
		if (sl_iterate_char_grid_width(&it->width_it, data) != FINISHED)
			return (LOOPED);
		if (data->it.row_index == 0)
			sl_iterate_char_grid_height(&it->height_it, data);
		if (sl_iterate_char_grid_height(&it->height_it, data) == FINISHED)
			break ;
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_init_it_char_grid(t_it_char_grid *it)
{
	ft_bzero(it, sizeof(t_it_char_grid));
}

////////////////////////////////////////////////////////////////////////////////
