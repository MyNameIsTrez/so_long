/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_monster.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 18:41:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 21:31:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	instantiate_monster(t_data *data)
{
	t_monster	monster;

	monster.entity = data->it.entity;
	sl_set_monster_heading(&monster, data);
	if (ft_vector_push(&data->monsters, &monster) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
