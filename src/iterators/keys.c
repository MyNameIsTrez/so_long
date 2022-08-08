/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/11 16:59:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 16:16:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_keys(t_iterator *it, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_count_iterator(MLX42_KEY_COUNT);
	while (ft_iterate(it) != FINISHED)
	{
		data->it.key = (keys_t)it->current;
		return (LOOPED);
	}
	data->it.key = (keys_t)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
