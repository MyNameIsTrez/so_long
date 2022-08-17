/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_invalid_character.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:33:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/17 16:29:23 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	check_invalid_character(t_data *data)
{
	t_iterator	it;

	ft_init_it(&it);
	while (sl_iterate_char_grid_characters(&it, data) != FINISHED)
		if (!ft_chr_in_str(data->it.char_grid_character, MAP_CHARACTERS))
			return (sl_set_error(SL_ERROR_FILE_HAS_INVALID_CHAR));
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
