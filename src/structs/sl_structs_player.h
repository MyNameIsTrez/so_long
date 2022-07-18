/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_player.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:55:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/18 12:27:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_PLAYER_H
# define SL_STRUCTS_PLAYER_H

////////////////////////////////////////////////////////////////////////////////

# define UP_MOVEMENT_KEY_INDEX 0
# define DOWN_MOVEMENT_KEY_INDEX 1
# define LEFT_MOVEMENT_KEY_INDEX 2
# define RIGHT_MOVEMENT_KEY_INDEX 3

typedef struct s_controls
{
	keys_t	movement_keys[4];
}	t_controls;

typedef struct s_player
{
	t_entity	*entity;
	t_controls	controls;
}	t_player;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
