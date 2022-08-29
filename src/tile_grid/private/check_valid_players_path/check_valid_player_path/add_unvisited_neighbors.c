/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_unvisited_neighbors.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 20:39:30 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 20:39:30 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "add_unvisited_neighbors/sl_private_add_unvisited_neighbors.h"

////////////////////////////////////////////////////////////////////////////////

t_status	add_unvisited_neighbors(t_tile *tile, t_tile ***visit_stack,
				bool *visited, t_data *data)
{
	t_iterator	it;

	ft_init_it(&it);
	while (sl_iterate_headings(&it, data) != FINISHED)
		if (try_add_neighbor(tile, visit_stack, visited, data) != OK)
			return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
