/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_iterator_frames.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 13:51:49 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 18:35:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_ITERATOR_FRAMES_H
# define SL_ITERATOR_FRAMES_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_data		t_data;
typedef struct s_tile_kind	t_tile_kind;

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_count(size_t frame_count, t_data *data);
void				sl_reset_iterate_frame_count(t_data *data);

t_iterator_status	sl_iterate_frame_height(mlx_image_t *frame, t_data *data);
void				sl_reset_iterate_frame_height(t_data *data);

t_iterator_status	sl_iterate_frame_pixel_indices(mlx_image_t *frame,
						t_data *data);
void				sl_reset_iterate_frame_pixel_indices(t_data *data);

t_iterator_status	sl_iterate_frame_pixels(mlx_image_t *frame, t_data *data);
void				sl_reset_iterate_frame_pixels(t_data *data);

t_iterator_status	sl_iterate_rgb_channel_indices(t_data *data);
void				sl_reset_iterate_rgb_channel_indices(t_data *data);

t_iterator_status	sl_iterate_frame_width(mlx_image_t *frame, t_data *data);
void				sl_reset_iterate_frame_width(t_data *data);

t_iterator_status	sl_iterate_frames_pixel_indices(t_tile_kind *tile_kind,
						t_data *data);
void				sl_reset_iterate_frames_pixel_indices(t_data *data);

t_iterator_status	sl_iterate_frames(t_tile_kind *tile_kind, t_data *data);
void				sl_reset_iterate_frames(t_data *data);

t_iterator_status	sl_iterate_frame_rgb_channel_indices(mlx_image_t *frame,
						t_data *data);
void				sl_reset_iterate_frame_rgb_channel_indices(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
