/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_tile_kinds.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/15 13:49:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/25 15:47:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TILE_KINDS_H
# define SL_TILE_KINDS_H

////////////////////////////////////////////////////////////////////////////////

# include "utils/sl_tile_kinds_utils.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_tile_kind_data
{
	t_i32				frame_count;
	t_i32				texture_row;
	t_u8				character;
	t_tile_kind_color	color;
}	t_tile_kind_data;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////