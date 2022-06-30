/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterators.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/30 15:04:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef ITERATORS_H
# define ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

# include "../so_long.h"

# include "loops/loops.h"

////////////////////////////////////////////////////////////////////////////////

typedef t_status	(*t_iterator_callback_char_grid_width)();



////////////////////////////////////////////////////////////////////////////////

typedef t_status	(*t_iterator_callback_char_grid_height)();

t_status	sl_iterate_char_grid_height(
				t_iterator_callback_char_grid_height callback);

////////////////////////////////////////////////////////////////////////////////

typedef t_status	(*t_iterator_callback_char_grid)(uint32_t column_index,
			uint32_t row_index, t_data *data);

t_status	sl_iterate_char_grid(t_iterator_callback_char_grid callback,
				t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
