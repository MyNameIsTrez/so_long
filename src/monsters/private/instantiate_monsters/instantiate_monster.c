/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_monster.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 18:41:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/25 19:18:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	instantiate_monster(t_data *data)
{
	t_monster	monster;

	monster.entity = data->it.entity;
	monster.heading = HEADING_NONE;
	if (ft_vector_push(&data->monsters, &monster) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
