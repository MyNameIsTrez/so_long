/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_char_grid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 14:40:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 15:35:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/init_char_grid/sl_private_init_char_grid.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_init_char_grid(char *map_filename, t_data *data)
{
	if (ft_read_grid_from_file(&data->char_grid, map_filename) != OK)
		return (ERROR);
	if (char_grid_has_invalid_character(data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
