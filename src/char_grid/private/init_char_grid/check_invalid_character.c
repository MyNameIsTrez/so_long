/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_invalid_character.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:33:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/10 13:51:40 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	check_invalid_character(t_data *data)
{
	t_it_char_grid	it;

	sl_init_it_char_grid(&it);
	while (sl_iterate_char_grid(&it, data) != FINISHED)
		if (!ft_chr_in_str(sl_get_char_grid_character(data), MAP_CHARACTERS))
			return (sl_set_error(SL_ERROR_FILE_HAS_INVALID_CHAR));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
