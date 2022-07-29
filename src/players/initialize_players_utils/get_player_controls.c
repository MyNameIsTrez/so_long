/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player_controls.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:06:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 20:06:10 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_controls	get_player_controls(t_i32 player_index)
{
	static const t_controls	players_controls[] = {
	{.movement_keys = {PLAYER_1_UP_KEY, PLAYER_1_DOWN_KEY,
		PLAYER_1_LEFT_KEY, PLAYER_1_RIGHT_KEY}},
	{.movement_keys = {PLAYER_2_UP_KEY, PLAYER_2_DOWN_KEY,
		PLAYER_2_LEFT_KEY, PLAYER_2_RIGHT_KEY}},
	};

	return (players_controls[player_index]);
}

////////////////////////////////////////////////////////////////////////////////
