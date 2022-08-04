/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_struct_entity.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:57:30 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/04 16:04:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCT_ENTITY_H
# define SL_STRUCT_ENTITY_H

////////////////////////////////////////////////////////////////////////////////

# include "../tiles/sl_struct_tiles.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_entity
{
	t_tile		tile;
	t_f64		last_frame_seconds;
	t_f64		seconds_per_frame;
}	t_entity;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
