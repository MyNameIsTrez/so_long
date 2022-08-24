/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collect_collectible.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 12:16:52 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 16:41:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_collect_collectible(t_collectible *collectible, t_data *data)
{
	collectible->collected = true;
	sl_hide_and_disable_entity(collectible->entity);
	data->collected_count++;
	if (data->collected_count == ft_vector_get_size(data->collectibles))
	{
		data->can_exit = true;
		sl_open_exit_locks(data);
	}
}

////////////////////////////////////////////////////////////////////////////////
