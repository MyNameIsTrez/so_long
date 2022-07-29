/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/11 16:59:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 20:57:37 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_keys(t_data *data, bool reset)
{
	static t_iterator	it;

	if (reset)
	{
		it.initialized = false;
		data->it.key = 0;
		return (RESET);
	}
	if (!it.initialized)
		it = ft_get_count_iterator(MLX42_KEY_COUNT);
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.key = (keys_t)it.current;
		return (LOOPED);
	}
	sl_reset_iterate_keys(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_keys(t_data *data)
{
	return (resettable_iterate_keys(data, false));
}

void	sl_reset_iterate_keys(t_data *data)
{
	resettable_iterate_keys(data, true);
}

////////////////////////////////////////////////////////////////////////////////
