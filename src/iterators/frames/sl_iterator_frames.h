/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_iterator_frames.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 13:51:49 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 19:07:22 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_ITERATOR_FRAMES_H
# define SL_ITERATOR_FRAMES_H

////////////////////////////////////////////////////////////////////////////////

# include "../sl_struct_iterators.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_data		t_data;
typedef struct s_tile_kind	t_tile_kind;

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_count(t_iterator *it, size_t frame_count,
						t_data *data);

t_iterator_status	sl_iterate_frame_pixel_indices(t_iterator *it,
						mlx_image_t *frame, t_data *data);

t_iterator_status	sl_iterate_frames(t_iterator *it, t_tile_kind *tile_kind,
						t_data *data);

t_iterator_status	sl_iterate_rgb_channel_indices(t_iterator *it,
						t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
