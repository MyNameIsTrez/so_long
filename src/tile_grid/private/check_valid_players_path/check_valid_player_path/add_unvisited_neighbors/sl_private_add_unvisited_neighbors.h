/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_add_unvisited_neighbors.h               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/26 20:40:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 20:40:11 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_ADD_UNVISITED_NEIGHBORS_H
# define SL_PRIVATE_ADD_UNVISITED_NEIGHBORS_H

////////////////////////////////////////////////////////////////////////////////

t_status	try_add_neighbor(t_heading heading, t_tile *tile,
				t_tile ***visit_stack, bool *visited, t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
