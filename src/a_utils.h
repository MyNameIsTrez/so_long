/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_utils.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/29 12:13:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/29 13:03:15 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef A_UTILS_H
# define A_UTILS_H

////////////////////////////////////////////////////////////////////////////////

# include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_data	t_data;

////////////////////////////////////////////////////////////////////////////////

typedef t_status	(*t_char_grid_iterate_callback)(uint32_t column_index,
			uint32_t row_index, t_data *data);

////////////////////////////////////////////////////////////////////////////////

t_status		sl_parse_argv(int argc, char **argv, t_data *data);
t_status		sl_load_texture(t_data *data);
t_status		sl_instantiate_tile_types(t_data *data);
t_status		sl_instantiate_tile_grid(t_data *data);
t_status		sl_instantiate_entities(t_data *data);
t_status		sl_instantiate_players(t_data *data);
t_status		sl_char_grid_iterate(t_char_grid_iterate_callback callback,
					t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
