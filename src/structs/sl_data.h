/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_data.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:55:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/11 17:32:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_DATA_H
# define SL_DATA_H

////////////////////////////////////////////////////////////////////////////////

// TODO: Rename data to d
typedef struct s_data
{
	t_t			t;
	uint32_t	held_keys[MLX42_KEY_COUNT];
	mlx_t		*mlx;
	t_grid		char_grid;
	t_window	window;
	t_texture	texture;
	uint32_t	tile_kind_count;
	t_tile_kind	tile_kinds[1 << (sizeof(char) * 8)];
	t_tile_grid	tile_grid;
	t_list		*entities;
	uint32_t	player_count;
	t_player	players[MAX_PLAYER_COUNT];
	double		seconds;
	uint32_t	frame;
}	t_data;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
