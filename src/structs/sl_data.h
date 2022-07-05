/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_data.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:55:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/05 15:26:38 by sbos          ########   odam.nl         */
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
	mlx_t		*mlx;
	t_window	window;
	t_texture	texture;
	uint32_t	tile_kind_count;
	t_tile_kind	tile_kinds[1 << (sizeof(char) * 8)];
	t_tile_grid	tile_grid;
	t_list		*entities;
	uint32_t	player_count;
	t_player	players[MAX_PLAYER_COUNT];
}	t_data;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
