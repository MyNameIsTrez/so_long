/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   missing_collectible.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 21:12:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 21:12:58 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	missing_collectible(t_data *data)
{
	t_iterator	it;

	ft_init_it(&it);
	while (sl_iterate_char_grid_characters(&it, data) != FINISHED)
		if (data->it.char_grid_character == COLLECTIBLE_CHARACTER)
			return (false);
	return (true);
}

////////////////////////////////////////////////////////////////////////////////
