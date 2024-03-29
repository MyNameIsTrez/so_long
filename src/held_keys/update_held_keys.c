/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_held_keys.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/11 16:39:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 16:43:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_update_held_keys(t_data *data)
{
	t_iterator	it;

	ft_init_it(&it);
	while (sl_iterate_keys(&it, data) != FINISHED)
	{
		if (mlx_is_key_down(data->mlx, data->it.key))
			data->held_keys[data->it.key]++;
		else
			data->held_keys[data->it.key] = 0;
	}
}

////////////////////////////////////////////////////////////////////////////////
