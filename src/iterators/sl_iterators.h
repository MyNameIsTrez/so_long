/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_iterators.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 13:28:36 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/17 16:27:04 by sbos          ########   odam.nl         */
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

t_iterator_status	sl_iterate_char_grid_characters(t_iterator *it,
						t_data *data);
t_iterator_status	sl_iterate_char_grid_indices(t_iterator *it, t_data *data);
t_iterator_status	sl_iterate_collectibles(t_iterator *it, t_data *data);
t_iterator_status	sl_iterate_entities(t_iterator *it, t_data *data);
t_iterator_status	sl_iterate_headings(t_iterator *it, t_data *data);
t_iterator_status	sl_iterate_keys(t_iterator *it, t_data *data);
t_iterator_status	sl_iterate_monsters(t_iterator *it, t_data *data);
t_iterator_status	sl_iterate_player_movement_keys(t_iterator *it,
						t_player *player, t_data *data);
t_iterator_status	sl_iterate_players(t_iterator *it, t_data *data);
t_iterator_status	sl_iterate_tile_kinds(t_iterator *it, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
