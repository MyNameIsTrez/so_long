/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   players.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 16:35:26 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 19:06:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_players(t_iterator *it, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_vector_iterator(data->players);
	if (ft_iterate(it) != FINISHED)
	{
		data->it.player = (t_player *)it->current;
		return (LOOPED);
	}
	data->it.player = (t_player *)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
