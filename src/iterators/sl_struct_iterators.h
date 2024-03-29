/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_struct_iterators.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 13:45:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 12:56:13 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCT_ITERATORS_H
# define SL_STRUCT_ITERATORS_H

////////////////////////////////////////////////////////////////////////////////

# include "../players/sl_struct_player.h"
# include "../entities/sl_struct_entity.h"
# include "../tile_kinds/sl_struct_tile_kind.h"
# include "../monsters/sl_struct_monster.h"
# include "../collectibles/sl_struct_collectible.h"
# include "../exit_locks/sl_struct_exit_lock.h"

////////////////////////////////////////////////////////////////////////////////

// This struct is used for temporary ITerator data storage
typedef struct s_it
{
	size_t			char_grid_index;
	size_t			frame_index;
	t_player		*player;
	t_entity		*entity;
	t_heading		heading;
	keys_t			key;
	t_u8			red;
	size_t			frame_pixel_index;
	size_t			rgb_channel_index;
	mlx_image_t		*frame;
	t_tile_kind		*tile_kind;
	keys_t			player_movement_key;
	t_monster		*monster;
	t_collectible	*collectible;
	t_u8			char_grid_character;
	t_exit_lock		*exit_lock;
}	t_it;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
