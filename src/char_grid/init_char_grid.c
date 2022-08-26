/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_char_grid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 14:40:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 13:54:41 by sbos          ########   odam.nl         */
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
	if (map_is_not_enclosed(data))
		return (sl_set_error(SL_ERROR_MAP_NOT_ENCLOSED));
	if (check_invalid_character(data) != OK)
		return (ERROR);
	if (has_basic_characters(data) != OK)
		return (ERROR);
	if (!BONUS && check_duplicate_start_or_exit_character(data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
