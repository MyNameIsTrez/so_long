/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_is_not_enclosed.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 13:34:52 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 15:03:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "map_is_not_enclosed/sl_private_map_is_not_enclosed.h"

////////////////////////////////////////////////////////////////////////////////

bool	map_is_not_enclosed(t_data *data)
{
	size_t	i;

	if (row_is_not_enclosed(0, data) || \
		row_is_not_enclosed(data->char_grid.height - 1, data))
		return (true);
	i = 1;
	while (i < data->char_grid.height - 1)
	{
		if (cell_is_not_wall(0, i, data) || \
			cell_is_not_wall(data->char_grid.width - 1, i, data))
			return (true);
		i++;
	}
	return (false);
}

////////////////////////////////////////////////////////////////////////////////
