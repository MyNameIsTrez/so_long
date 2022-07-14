/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_structs_player.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:55:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 12:58:05 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_STRUCTS_PLAYER_H
# define SL_STRUCTS_PLAYER_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_controls
{
	keys_t		up_key;
	keys_t		down_key;
	keys_t		left_key;
	keys_t		right_key;
}	t_controls;

typedef struct s_player
{
	t_entity	*entity;
	t_controls	controls;
}	t_player;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
