/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_duplicate_start_or_exit_character.c          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:33:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/17 16:47:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	check_duplicate_start_or_exit_character(t_data *data)
{
	t_iterator	it;
	bool		start_seen;
	bool		exit_seen;

	ft_init_it(&it);
	start_seen = false;
	exit_seen = false;
	while (sl_iterate_char_grid_characters(&it, data) != FINISHED)
	{
		if (ft_chr_in_str(data->it.char_grid_character, PLAYER_CHARACTERS))
		{
			if (start_seen)
				return (sl_set_error(SL_ERROR_FILE_HAS_DUPLICATE_CHAR));
			start_seen = true;
		}
		if (data->it.char_grid_character == MAP_EXIT_CHARACTER)
		{
			if (exit_seen)
				return (sl_set_error(SL_ERROR_FILE_HAS_DUPLICATE_CHAR));
			exit_seen = true;
		}
	}
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
