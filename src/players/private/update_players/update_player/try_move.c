/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_move.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 10:37:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 12:44:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "try_move/sl_private_try_move.h"

////////////////////////////////////////////////////////////////////////////////

void	try_move(t_player *player, t_data *data)
{
	t_iterator	it;
	t_heading	heading;

	while (sl_iterate_headings(&it, data) != FINISHED)
	{
		heading = data->it.heading;
		if (trying_to_move(player, heading, data))
		{
			if (can_walk(heading, &player->entity->tile, data))
			{
				shift_tile_pos_to_heading(&player->entity->tile, heading, data);
				data->movement_count++;
				ft_printf("Movement count: %u\n", data->movement_count);
			}
			else if (BONUS)
				update_death_state(player, heading, data);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
