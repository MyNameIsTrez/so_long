/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/01 18:25:51 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SO_LONG_H
# define SO_LONG_H

////////////////////////////////////////////////////////////////////////////////

# include "MLX42/MLX42.h"

////////////////////////////////////////////////////////////////////////////////

# include "libft.h"
# include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

# include "sl_settings.h"
# include "sl_structs.h"

////////////////////////////////////////////////////////////////////////////////

# include "a_utils.h"
# include "iterators/iterators.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_parse_argv(int argc, char **argv, t_data *data);
t_status	sl_load_texture(t_data *data);
t_status	sl_instantiate_tile_kinds(t_data *data);
t_status	sl_instantiate_tile_grid(t_data *data);
t_status	sl_instantiate_entities(t_data *data);
t_status	sl_instantiate_players(t_data *data);

void		sl_cleanup(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
