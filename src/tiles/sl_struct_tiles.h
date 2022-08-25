/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_struct_tiles.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:58:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 16:39:58 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCT_TILES_H
# define SL_STRUCT_TILES_H

////////////////////////////////////////////////////////////////////////////////

# include "../tile_kinds/sl_struct_tile_kind.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_initial_tile
{
	size_t	frame_index;
	size_t	index;
}	t_initial_tile;

typedef struct s_tile
{
	t_initial_tile	initial;
	t_tile_kind		*tile_kind;
	size_t			frame_index;
	size_t			*frame_instances_indices;
	size_t			index;
}	t_tile;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
