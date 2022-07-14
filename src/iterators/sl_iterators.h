/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_iterators.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 12:09:04 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_ITERATORS_H
# define SL_ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

# include "frame_pixels/sl_iterator_frame_pixels.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid_width(t_data *data);
void				sl_reset_iterate_char_grid_width(t_data *data);

t_iterator_status	sl_iterate_char_grid_height(t_data *data);
void				sl_reset_iterate_char_grid_height(t_data *data);

t_iterator_status	sl_iterate_char_grid(t_data *data);
void				sl_reset_iterate_char_grid(t_data *data);

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_frame_count(uint32_t frame_count, t_data *data);
void				sl_reset_iterate_frame_count(t_data *data);

t_iterator_status	sl_iterate_frames(t_tile_kind *tile_kind, t_data *data);
void				sl_reset_iterate_frames(t_data *data);

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_player_count(t_data *data);
void				sl_reset_iterate_player_count(t_data *data);

t_iterator_status	sl_iterate_tile_kind_count(t_data *data);
void				sl_reset_iterate_tile_kind_count(t_data *data);

t_iterator_status	sl_iterate_entities(t_data *data);
void				sl_reset_iterate_entities(t_data *data);

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_keys(t_data *data);
void				sl_reset_iterate_keys(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
