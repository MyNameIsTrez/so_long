/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_data.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:55:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/18 15:19:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_DATA_H
# define SL_STRUCTS_DATA_H

////////////////////////////////////////////////////////////////////////////////

# include "../monitor/sl_struct_monitor.h"
# include "../iterators/sl_struct_iterators.h"
# include "sl_structs_mlx42.h"
# include "../window/sl_struct_window.h"
# include "../texture/sl_struct_texture.h"
# include "../tile_kinds/sl_struct_tile_kind.h"
# include "../tile_grid/sl_struct_tile_grid.h"
# include "../entities/sl_struct_entity.h"
# include "../players/sl_struct_player.h"
# include "../monsters/sl_struct_monster.h"
# include "../collectibles/sl_struct_collectible.h"

////////////////////////////////////////////////////////////////////////////////

// This struct is used for so_long DATA storage
typedef struct s_data
{
	t_monitor		monitor;
	t_it			it;
	t_i32			held_keys[MLX42_KEY_COUNT];
	mlx_t			*mlx;
	t_char_grid		char_grid;
	t_window		window;
	t_texture		texture;
	t_tile_kind		*tile_kinds;
	t_tile_grid		tile_grid;
	t_entity		*entities;
	t_player		*players;
	t_monster		*monsters;
	t_collectible	*collectibles;
	size_t			collected_count;
	t_u32			ticks;
	bool			can_exit;
	bool			finished_level;
}	t_data;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
