/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monsters.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 16:35:26 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 16:17:43 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_monsters(t_iterator *it, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_vector_iterator(data->monsters);
	while (ft_iterate(it) != FINISHED)
	{
		data->it.monster = (t_monster *)it->current;
		return (LOOPED);
	}
	data->it.monster = (t_monster *)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
