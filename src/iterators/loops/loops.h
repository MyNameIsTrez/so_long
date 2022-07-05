/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loops.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/30 15:04:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/05 14:06:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef LOOPS_H
# define LOOPS_H

////////////////////////////////////////////////////////////////////////////////

#include "../../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_loop_status	sl_loop_char_grid_height(uint32_t *row_index_ptr, t_data *data,
					bool reset);

t_loop_status	sl_loop_char_grid(uint32_t *column_index_ptr,
					uint32_t *row_index_ptr, t_data *data, bool reset);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
