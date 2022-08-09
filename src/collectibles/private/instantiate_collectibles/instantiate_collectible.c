/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_collectible.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 16:39:10 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/09 16:39:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	instantiate_collectible(t_data *data)
{
	t_collectible	collectible;

	collectible.entity = data->it.entity;
	if (ft_vector_push(&data->collectibles, &collectible) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
