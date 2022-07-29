/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_grid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 14:40:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 14:42:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC bool	grid_has_invalid_character(t_data *data)
{
	while (sl_iterate_char_grid(data) != FINISHED)
		if (!ft_chr_in_str(sl_get_char_grid_character(data), MAP_CHARACTERS))
			return (sl_set_error(SL_ERROR_FILE_HAS_INVALID_CHAR));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_init_grid(char *map_filename, t_data *data)
{
	if (ft_read_grid_from_file(&data->char_grid, map_filename) != OK)
		return (sl_any_error());
	if (grid_has_invalid_character(data) != OK)
		return (sl_any_error());
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
