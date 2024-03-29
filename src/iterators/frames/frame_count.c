/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_count.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:56:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 19:06:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_count(t_iterator *it, size_t frame_count,
						t_data *data)
{
	if (!it->initialized)
		*it = ft_get_count_iterator(frame_count);
	if (ft_iterate(it) != FINISHED)
	{
		data->it.frame_index = (size_t)it->current;
		return (LOOPED);
	}
	data->it.frame_index = (size_t)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
