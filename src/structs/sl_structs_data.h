/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_data.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:55:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/26 11:19:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_DATA_H
# define SL_STRUCTS_DATA_H

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
	t_i32		player_count;
	t_player	players[MAX_PLAYER_COUNT];
	t_f64		seconds;
	t_i32		frame;
}	t_data;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
