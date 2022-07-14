/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_iterator_frame_pixels.h                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 13:51:49 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 11:42:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_ITERATOR_FRAME_PIXELS_H
# define SL_ITERATOR_FRAME_PIXELS_H

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_width(mlx_image_t *frame, t_data *data);
void				sl_reset_iterate_frame_width(t_data *data);

t_iterator_status	sl_iterate_frame_height(mlx_image_t *frame, t_data *data);
void				sl_reset_iterate_frame_height(t_data *data);

t_iterator_status	sl_iterate_frame_pixels(mlx_image_t *frame, t_data *data);
void				sl_reset_iterate_frame_pixels(t_data *data);

t_iterator_status	sl_iterate_channel_indices(t_data *data);
void				sl_reset_iterate_channel_indices(t_data *data);

t_iterator_status	sl_iterate_frame_channels(mlx_image_t *frame, t_data *data);
void				sl_reset_iterate_frame_channels(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
