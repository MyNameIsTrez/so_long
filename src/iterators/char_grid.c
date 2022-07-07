/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:55:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/07 14:39:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid(t_data *data)
{
	while (true)
	{
		while (true)
		{
			if (sl_iterate_char_grid_width(data) != LOOPED)
				break ;
			return (LOOPED);
		}
		sl_reset_iterate_char_grid_width(data);
		if (sl_iterate_char_grid_height(data) != LOOPED)
			break ;
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_reset_iterate_char_grid(t_data *data)
{
	sl_reset_iterate_char_grid_height(data);
	sl_iterate_char_grid_height(data);
	sl_reset_iterate_char_grid_width(data);
}

////////////////////////////////////////////////////////////////////////////////
