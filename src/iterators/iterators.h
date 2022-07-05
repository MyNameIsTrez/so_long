/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterators.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/05 14:06:55 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef ITERATORS_H
# define ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

# include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

typedef t_status	(*t_iterator_callback_char_grid_height)\
			(uint32_t row_index, t_data *data);

t_status	sl_iterate_char_grid_height(
				t_iterator_callback_char_grid_height callback, t_data *data);

////////////////////////////////////////////////////////////////////////////////

typedef t_status	(*t_iterator_callback_char_grid)(uint32_t column_index,
			uint32_t row_index, t_data *data);

t_status	sl_iterate_char_grid(t_iterator_callback_char_grid callback,
				t_data *data);

////////////////////////////////////////////////////////////////////////////////

// TODO: Rename to t_iterate_status
t_loop_status	sl_iterate_frame_count(uint32_t frame_count, t_data *data,
					bool reset);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
