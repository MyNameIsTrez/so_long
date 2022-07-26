/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   players.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 16:35:26 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/26 17:14:15 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_players(t_data *data,
								bool reset)
{
	static t_iterator	it;

	if (!it.initialized || reset)
	{
		it = ft_get_range_start_0_iterator((t_i32)ft_vector_get_size(data->players));
		it.initialized = true;
	}
	if (reset)
		return (RESET);
	while (ft_iterate(&it) != FINISHED)
	{
		// TODO: Replace with pointer iterator
		data->it.player = &data->players[(t_i32)it.current];
		return (LOOPED);
	}
	sl_reset_iterate_players(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_players(t_data *data)
{
	return (resettable_iterate_players(data, false));
}

void	sl_reset_iterate_players(t_data *data)
{
	resettable_iterate_players(data, true);
}

////////////////////////////////////////////////////////////////////////////////
