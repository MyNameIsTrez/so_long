/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 13:52:38 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 14:52:21 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_width(t_iterator *it, mlx_image_t *frame,
						t_data *data)
{
	if (!it->initialized)
		*it = ft_get_count_iterator(frame->width);
	while (ft_iterate(it) != FINISHED)
	{
		data->it.frame_pixels.x = (size_t)it->current;
		return (LOOPED);
	}
	data->it.frame_pixels.x = (size_t)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
