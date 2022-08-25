/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_collectibles.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 16:56:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 17:07:47 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	reset_collectibles(t_data *data)
{
	t_iterator		it;
	t_collectible	*collectible;

	ft_init_it(&it);
	while (sl_iterate_collectibles(&it, data) != FINISHED)
	{
		collectible = data->it.collectible;
		collectible->collected = false;
		sl_change_frame(&collectible->entity->tile, 0);
		collectible->entity->animated = true;
	}
}

////////////////////////////////////////////////////////////////////////////////
