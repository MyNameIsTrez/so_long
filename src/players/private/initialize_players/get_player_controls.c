/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player_controls.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:06:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 20:35:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_controls	get_player_controls(t_u8 character)
{
	static const t_controls	players_controls[] = {
	[PLAYER_1_CHARACTER] = {.movement_keys = {PLAYER_1_UP_KEY,
		PLAYER_1_RIGHT_KEY, PLAYER_1_DOWN_KEY, PLAYER_1_LEFT_KEY}},
	[PLAYER_2_CHARACTER] = {.movement_keys = {PLAYER_2_UP_KEY,
		PLAYER_2_RIGHT_KEY, PLAYER_2_DOWN_KEY, PLAYER_2_LEFT_KEY}},
	};

	return (players_controls[character]);
}

////////////////////////////////////////////////////////////////////////////////
