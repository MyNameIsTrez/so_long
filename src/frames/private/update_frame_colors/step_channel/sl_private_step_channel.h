/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_step_channel.h                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 17:40:03 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 18:24:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_STEP_CHANNEL_H
# define SL_PRIVATE_STEP_CHANNEL_H

////////////////////////////////////////////////////////////////////////////////

void	bounce_high(t_i32 *step_ptr, t_u8 *channel, t_u8 min_channel,
			t_u8 max_channel);
void	bounce_low(t_i32 *step_ptr, t_u8 *channel, t_u8 min_channel,
			t_u8 max_channel);

t_u8	*get_channel_ptr(size_t rgb_channel_index, mlx_image_t *frame,
			t_data *data);
t_i32	*get_channel_step_ptr(size_t rgb_channel_index, t_data *data);
t_u8	get_max_channel(size_t rgb_channel_index, t_u8 original_channel,
			t_data *data);
t_u8	get_min_channel(size_t rgb_channel_index, t_u8 original_channel,
			t_data *data);
t_u8	get_original_channel(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
