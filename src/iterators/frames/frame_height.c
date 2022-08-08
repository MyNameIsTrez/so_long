/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_height.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 13:54:24 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 14:51:15 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_height(t_iterator *it, mlx_image_t *frame,
						t_data *data)
{
	if (!it->initialized)
		*it = ft_get_count_iterator(frame->height);
	while (ft_iterate(it) != FINISHED)
	{
		data->it.frame_pixels.y = (size_t)it->current;
		return (LOOPED);
	}
	data->it.frame_pixels.y = (size_t)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
