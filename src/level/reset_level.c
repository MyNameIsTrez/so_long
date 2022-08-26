/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_level.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 14:01:43 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 17:06:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/reset_level/sl_private_reset_level.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_reset_level(t_data *data)
{
	reset_collectibles(data);
	reset_exit_locks(data);
	reset_monsters(data);
	reset_players(data);
	data->can_exit = false;
	data->collected_count = 0;
	data->finished_level = false;
	data->movement_count = 0;
}

////////////////////////////////////////////////////////////////////////////////
