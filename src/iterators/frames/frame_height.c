/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_height.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 13:54:24 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 17:40:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_frame_height(mlx_image_t *frame,
								t_data *data, bool reset)
{
	static t_iterator	it;

	if (reset)
	{
		it.initialized = false;
		data->it.frame_pixels.y = 0;
		return (RESET);
	}
	if (!it.initialized)
		it = ft_get_count_iterator(frame->height);
	while (ft_iterate(&it) != FINISHED)
	{
		data->it.frame_pixels.y = (size_t)it.current;
		return (LOOPED);
	}
	sl_reset_iterate_frame_height(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_height(mlx_image_t *frame, t_data *data)
{
	return (resettable_iterate_frame_height(frame, data, false));
}

void	sl_reset_iterate_frame_height(t_data *data)
{
	resettable_iterate_frame_height(NULL, data, true);
}

////////////////////////////////////////////////////////////////////////////////
