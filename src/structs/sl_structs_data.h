/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_data.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:55:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 17:46:54 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_DATA_H
# define SL_STRUCTS_DATA_H

////////////////////////////////////////////////////////////////////////////////

# define CHAR_COUNT 256

////////////////////////////////////////////////////////////////////////////////

// This struct is used for so_long DATA storage.
typedef struct s_data
{
	t_it		it;
	t_i32		held_keys[MLX42_KEY_COUNT];
	mlx_t		*mlx;
	t_grid		char_grid;
	t_window	window;
	t_texture	texture;
	t_i32		tile_kind_count;
	t_tile_kind	tile_kinds[CHAR_COUNT];
	t_tile_grid	tile_grid;
	t_list		*entities;
	t_i32		player_count;
	t_player	players[MAX_PLAYER_COUNT];
	t_f64		seconds;
	t_i32		frame;
}	t_data;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
