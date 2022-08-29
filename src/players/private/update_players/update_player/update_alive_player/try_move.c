/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   try_move.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 10:37:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 17:55:58 by sbos          ########   odam.nl         */
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

	ft_init_it(&it);
	while (sl_iterate_headings(&it, data) != FINISHED)
	{
		if (trying_to_move(player, data))
		{
			if (sl_can_walk(data->it.heading, &player->entity->tile, data))
			{
				sl_shift_tile_pos_to_heading(&player->entity->tile,
					data->it.heading, data);
				data->movement_count++;
				ft_printf("Movement count: %u\n", data->movement_count);
			}
			else if (BONUS)
				update_death_state(player, data);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
