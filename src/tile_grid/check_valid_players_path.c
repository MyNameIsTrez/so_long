/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_valid_players_path.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 20:52:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 20:52:18 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/check_valid_players_path/\
sl_private_check_valid_players_path.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_check_valid_players_path(t_data *data)
{
	t_iterator	it;

	ft_init_it(&it);
	while (sl_iterate_players(&it, data) != FINISHED)
		if (check_valid_player_path(data->it.player, data) != OK)
			return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
