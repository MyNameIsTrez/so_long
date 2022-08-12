/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_frame_colors.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 11:00:12 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 14:04:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/update_frame_colors/sl_private_update_frame_colors.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/sl_private_frames.h"

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Predicts what the color will be after a step
 * and uses that to change the rgb_step correctly:
 * So if R is 2 and step is -3, R should end up as 2 -> 1 -> 0 -> 1, so 1
 * If R is 253 and step is 6, R should end up as
 * 253 -> 254 -> 255 -> 254 -> 253 -> 252 -> 251, so 251
 * @param data
 */
void	sl_update_frame_colors(t_data *data)
{
	t_iterator	tile_kinds_it;
	t_iterator	frame_count_it;
	mlx_image_t	*frame;
	t_iterator	frame_pixel_indices_it;
	t_iterator	rgb_channel_indices_it;

	ft_init_it(&tile_kinds_it);
	ft_init_it(&frame_count_it);
	ft_init_it(&frame_pixel_indices_it);
	ft_init_it(&rgb_channel_indices_it);
	while (sl_iterate_tile_kinds(&tile_kinds_it, data) != FINISHED)
		while (sl_iterate_frame_count(&frame_count_it, data->it.tile_kind->frame_count, data) != FINISHED)
		{
			frame = data->it.tile_kind->frames[data->it.frame_index];
			while (sl_iterate_frame_pixel_indices(&frame_pixel_indices_it, frame, data) != FINISHED)
				while (sl_iterate_rgb_channel_indices(&rgb_channel_indices_it,
						data) != FINISHED)
					if (should_step(data) && is_visible(frame, data))
						step_pixel(frame, data);
		}
}

////////////////////////////////////////////////////////////////////////////////
