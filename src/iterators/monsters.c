/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monsters.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 16:35:26 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/04 16:08:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_monsters(t_data *data,
								bool reset)
{
	static t_iterator	it;

	if (reset)
	{
		it.initialized = false;
		data->it.monster = NULL;
		return (RESET);
	}
	if (!it.initialized)
		it = ft_get_vector_iterator(data->monsters);
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.monster = (t_monster *)it.current;
		return (LOOPED);
	}
	sl_reset_iterate_monsters(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_monsters(t_data *data)
{
	return (resettable_iterate_monsters(data, false));
}

void	sl_reset_iterate_monsters(t_data *data)
{
	resettable_iterate_monsters(data, true);
}

////////////////////////////////////////////////////////////////////////////////
