/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_iterator_frames.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 13:51:49 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/15 15:15:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_ITERATOR_FRAMES_H
# define SL_ITERATOR_FRAMES_H

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_channel_indices(t_data *data);
void				sl_reset_iterate_channel_indices(t_data *data);

t_iterator_status	sl_iterate_frames_byte_indices(t_tile_kind *tile_kind,
						t_data *data);
void				sl_reset_iterate_frames_byte_indices(t_data *data);

t_iterator_status	sl_iterate_frame_channel_indices(mlx_image_t *frame,
						t_data *data);
void				sl_reset_iterate_frame_channels(t_data *data);

t_iterator_status	sl_iterate_frame_count(t_i32 frame_count, t_data *data);
void				sl_reset_iterate_frame_count(t_data *data);

t_iterator_status	sl_iterate_frame_height(mlx_image_t *frame, t_data *data);
void				sl_reset_iterate_frame_height(t_data *data);

t_iterator_status	sl_iterate_frame_pixel_indices(mlx_image_t *frame,
						t_data *data);
void				sl_reset_iterate_frame_pixel_indices(t_data *data);

t_iterator_status	sl_iterate_frame_pixels(mlx_image_t *frame, t_data *data);
void				sl_reset_iterate_frame_pixels(t_data *data);

t_iterator_status	sl_iterate_frame_width(mlx_image_t *frame, t_data *data);
void				sl_reset_iterate_frame_width(t_data *data);

t_iterator_status	sl_iterate_frame_byte_indices(mlx_image_t *frame,
						t_data *data);
void				sl_reset_iterate_frame_byte_indices(t_data *data);

t_iterator_status	sl_iterate_frames(t_tile_kind *tile_kind, t_data *data);
void				sl_reset_iterate_frames(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
