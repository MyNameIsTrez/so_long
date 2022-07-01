/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterators.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/01 14:12:18 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef ITERATORS_H
# define ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

# include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

typedef t_status	(*t_iterator_callback_char_grid_height)(uint32_t row_index, t_data *data);

t_status	sl_iterate_char_grid_height(t_iterator_callback_char_grid_height callback, t_data *data);

////////////////////////////////////////////////////////////////////////////////

typedef t_status	(*t_iterator_callback_char_grid)(uint32_t column_index,
			uint32_t row_index, t_data *data);

t_status	sl_iterate_char_grid(t_iterator_callback_char_grid callback,
				t_data *data);

////////////////////////////////////////////////////////////////////////////////

typedef struct s_loop_args_frame_count
{
	uint32_t	frame_count;
}	t_loop_args_frame_count;

typedef struct s_generated_args_frame_count
{
	uint32_t	frame_index;
}	t_generated_args_frame_count;

typedef struct s_tile	t_tile;

typedef struct s_callback_args_frame_count
{
	t_tile		*tile;
	uint32_t	column_index;
	uint32_t	row_index;
}	t_callback_args_initialize_frame_instance;

typedef t_status	(*t_iterator_callback_frame_count)(
			t_generated_args_frame_count *generated_args,
			t_callback_args_initialize_frame_instance *callback_args,
			t_data *data);

t_status	sl_iterate_frame_count(t_loop_args_frame_count *loop_args,
			void *callback_args, t_iterator_callback_frame_count callback,
			t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
