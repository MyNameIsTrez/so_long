/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_temporary.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 13:45:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/07 16:00:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TEMPORARY_H
# define SL_TEMPORARY_H

////////////////////////////////////////////////////////////////////////////////

// This struct is used for Temporary iterator counter storage.
typedef struct s_it
{
	uint32_t	column_index;
	uint32_t	row_index;
	uint32_t	frame_index;
	uint32_t	player_index;
	uint32_t	tile_kind_index;
	t_list		*entities;
}	t_it;

////////////////////////////////////////////////////////////////////////////////

// This struct is used for Temporary data storage. Used by iterators.
typedef struct s_t
{
	t_it		it;
	uint32_t	column_index;
	uint32_t	row_index;
	uint32_t	frame_index;
	uint32_t	player_index;
	uint32_t	tile_kind_index;
	t_entity	*entity;
}	t_t;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
