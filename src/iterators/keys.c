/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/11 16:59:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_keys(t_data *data, bool reset)
{
	static keys_t	key;

	if (reset)
	{
		key = 0;
		return (RESET);
	}
	while (key < MLX42_KEY_COUNT)
	{
		data->it.key = key;
		key++;
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
