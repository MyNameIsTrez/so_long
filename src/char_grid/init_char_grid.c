/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_char_grid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 14:40:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/17 16:43:55 by sbos          ########   odam.nl         */
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
	if (check_invalid_character(data) != OK)
		return (ERROR);
	if (!BONUS && check_duplicate_start_or_exit_character(data) != OK)
		return (ERROR);
	if (check_valid_path(data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
