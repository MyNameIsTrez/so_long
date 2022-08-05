/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_monster.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/05 18:41:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 19:25:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "instantiate_monster/sl_private_instantiate_monster.h"

////////////////////////////////////////////////////////////////////////////////

t_status	instantiate_monster(t_data *data)
{
	t_monster	monster;

	monster.entity = data->it.entity;
	set_heading(&monster, data);
	if (ft_vector_push(&data->monsters, &monster) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
