/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_pixel_indices.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 15:09:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/10 17:07:24 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_pixel_indices(t_iterator *it,
						mlx_image_t *frame, t_data *data)
{
	if (!it->initialized)
		*it = ft_get_iterator(0, frame->width * frame->height * 4, 4);
	while (ft_iterate(it) != FINISHED)
	{
		data->it.frame_pixel_index = (size_t)it->current;
		return (LOOPED);
	}
	data->it.frame_pixel_index = (size_t)it->current;
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////
