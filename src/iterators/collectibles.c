/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectibles.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 16:20:10 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 16:32:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_collectibles(t_iterator *it, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_vector_iterator(data->collectibles);
	while (ft_iterate(it) != FINISHED)
	{
		data->it.collectible = (t_collectible *)it->current;
		return (LOOPED);
	}
	data->it.collectible = (t_collectible *)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
