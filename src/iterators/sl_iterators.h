/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_iterators.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 14:25:43 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_ITERATORS_H
# define SL_ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

# include "frames/sl_iterator_frames.h"
# include "sl_structs_nested_iterators.h"
# include "sl_struct_iterators.h"

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_char_grid_height(t_iterator *it, t_data *data);

t_iterator_status	sl_iterate_char_grid_width(t_iterator *it, t_data *data);

t_iterator_status	sl_iterate_char_grid(t_it_char_grid *it, t_data *data);
void				sl_init_it_char_grid(t_it_char_grid *it);

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_entities(t_iterator *it, t_data *data);

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_heading(t_data *data);
void				sl_reset_iterate_heading(t_data *data);

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_keys(t_data *data);
void				sl_reset_iterate_keys(t_data *data);

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_monsters(t_data *data);
void				sl_reset_iterate_monsters(t_data *data);

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_player_movement_keys(t_player *player,
						t_data *data);
void				sl_reset_iterate_player_movement_keys(t_data *data);

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_players(t_data *data);
void				sl_reset_iterate_players(t_data *data);

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_tile_kinds(t_data *data);
void				sl_reset_iterate_tile_kinds(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
