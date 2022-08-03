/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_data.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:55:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/03 18:00:48 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_DATA_H
# define SL_STRUCTS_DATA_H

////////////////////////////////////////////////////////////////////////////////

# include "../monitor/sl_struct_monitor.h"
# include "../iterators/sl_struct_iterators.h"
# include "../window/sl_struct_window.h"
# include "../texture/sl_struct_texture.h"
# include "../tile_kinds/sl_struct_tile_kind.h"
# include "../tile_grid/sl_struct_tile_grid.h"
# include "../entities/sl_struct_entity.h"
# include "../players/sl_struct_player.h"

////////////////////////////////////////////////////////////////////////////////

// This struct is used for so_long DATA storage
typedef struct s_data
{
	t_monitor	monitor;
	t_it		it;
	t_i32		held_keys[MLX42_KEY_COUNT];
	mlx_t		*mlx;
	t_grid		char_grid;
	t_window	window;
	t_texture	texture;
	t_tile_kind	*tile_kinds;
	t_tile_grid	tile_grid;
	t_entity	*entities;
	t_player	*players;
	t_f64		seconds;
	t_u32		frame;
}	t_data;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
