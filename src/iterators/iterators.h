/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterators.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/07 15:20:14 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef ITERATORS_H
# define ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

# include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid_width(t_data *data);
void				sl_reset_iterate_char_grid_width(t_data *data);

t_iterator_status	sl_iterate_char_grid_height(t_data *data);
void				sl_reset_iterate_char_grid_height(t_data *data);

t_iterator_status	sl_iterate_char_grid(t_data *data);
void				sl_reset_iterate_char_grid(t_data *data);


t_iterator_status	sl_iterate_frame_count(uint32_t frame_count, t_data *data);
void				sl_reset_iterate_frame_count(t_data *data);

t_iterator_status	sl_iterate_player_count(t_data *data);
void				sl_reset_iterate_player_count(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
