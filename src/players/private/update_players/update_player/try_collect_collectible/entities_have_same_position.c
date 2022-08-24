/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entities_have_same_position.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/11 16:42:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 16:42:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

bool	sl_entities_have_same_position(t_entity *entity_1, t_entity *entity_2)
{
	return (entity_1->tile.index == entity_2->tile.index);
}

////////////////////////////////////////////////////////////////////////////////