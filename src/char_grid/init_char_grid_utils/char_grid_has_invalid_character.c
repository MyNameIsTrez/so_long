/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_grid_has_invalid_character.c                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:33:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 19:44:47 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	char_grid_has_invalid_character(t_data *data)
{
	while (sl_iterate_char_grid(data) != FINISHED)
		if (!ft_chr_in_str(sl_get_char_grid_character(data), MAP_CHARACTERS))
			return (sl_set_error(SL_ERROR_FILE_HAS_INVALID_CHAR));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
