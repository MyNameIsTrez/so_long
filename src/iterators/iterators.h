/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterators.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/29 17:10:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef ITERATORS_H
# define ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

# include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

// typedef t_status	(*t_char_grid_width_callback)();

////////////////////////////////////////////////////////////////////////////////

typedef t_status	(*t_char_grid_iterate_callback)(uint32_t column_index,
			uint32_t row_index, t_data *data);

t_status	sl_char_grid_iterate(t_char_grid_iterate_callback callback,
				t_data *data);

// int	sl_char_grid_iterate2(uint32_t *column_index_res, uint32_t *row_index_res,
// 			t_data *data, bool reset);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
