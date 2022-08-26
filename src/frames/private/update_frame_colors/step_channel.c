/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   step_channel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 16:57:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 18:23:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "step_channel/sl_private_step_channel.h"

////////////////////////////////////////////////////////////////////////////////

void	step_channel(size_t rgb_channel_index, mlx_image_t *frame, t_data *data)
{
	t_u8		*channel;
	t_i32		*step_ptr;
	t_u8		original_channel;
	t_u8		min_channel;
	t_u8		max_channel;

	channel = get_channel_ptr(rgb_channel_index, frame, data);
	step_ptr = get_channel_step_ptr(rgb_channel_index, data);
	original_channel = get_original_channel(data);
	min_channel = get_min_channel(rgb_channel_index, original_channel, data);
	max_channel = get_max_channel(rgb_channel_index, original_channel, data);
	if (*channel + *step_ptr < min_channel)
		bounce_low(step_ptr, channel, min_channel, max_channel);
	else if (*channel + *step_ptr > max_channel)
		bounce_high(step_ptr, channel, min_channel, max_channel);
	else
		*channel += *step_ptr;
}

////////////////////////////////////////////////////////////////////////////////
