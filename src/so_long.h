/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 11:26:26 by sbos          ########   odam.nl         */
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

# include "error/sl_error.h"

////////////////////////////////////////////////////////////////////////////////

# include "settings/sl_settings.h"
# include "structs/sl_structs.h"

////////////////////////////////////////////////////////////////////////////////

# include "held_keys/sl_held_keys.h"

////////////////////////////////////////////////////////////////////////////////

# include "players/sl_players.h"

////////////////////////////////////////////////////////////////////////////////

# include "frames/sl_frames.h"

////////////////////////////////////////////////////////////////////////////////

# include "utils/sl_utils.h"

////////////////////////////////////////////////////////////////////////////////

# include "iterators/sl_iterators.h"

////////////////////////////////////////////////////////////////////////////////

# include "tiles/sl_tiles.h"

////////////////////////////////////////////////////////////////////////////////

# include "grid/sl_grid.h"

////////////////////////////////////////////////////////////////////////////////

# include "entities/sl_entities.h"

////////////////////////////////////////////////////////////////////////////////

# include "background/sl_background.h"

////////////////////////////////////////////////////////////////////////////////

# include "cleanup/sl_cleanup.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_parse_argv(int argc, char **argv, t_data *data);
t_status	sl_load_texture(t_data *data);
t_status	sl_instantiate_tile_kinds(t_data *data);
t_status	sl_instantiate_tile_grid(t_data *data);
t_status	sl_instantiate_entities(t_data *data);
t_status	sl_instantiate_players(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
