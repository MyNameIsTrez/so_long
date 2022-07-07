/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_count.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:56:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/06 15:56:32 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_count(uint32_t frame_count, t_data *data)
{
	while (data->t.it.frame_index < frame_count)
	{
		data->t.frame_index = data->t.it.frame_index;
		data->t.it.frame_index++;
		return (LOOPED);
	}
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

void	sl_reset_iterate_frame_count(t_data *data)
{
	data->t.it.frame_index = 0;
}

////////////////////////////////////////////////////////////////////////////////
