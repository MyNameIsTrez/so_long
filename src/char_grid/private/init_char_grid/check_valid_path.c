/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_valid_path.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/10 13:48:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/10 16:18:18 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "check_valid_path/sl_private_check_valid_path.h"

////////////////////////////////////////////////////////////////////////////////

// size_t	get_index_from_xy(size_t x, size_t y, t_data *data)
// {
// 	return (x + y * data->char_grid.width);
// }

// t_status	try_add_neighbor(size_t index, t_i32 column_offset, t_i32 row_offset, size_t **visit_stack, bool *visited)
// {
// 	if (ft_vector_push(, visit_stack, ) != OK)
// 		return (ERROR);
// }

// t_status	add_unvisited_neighbors(size_t index, size_t **visit_stack, bool *visited)
// {
// 	if (try_add_neighbor(index, 0, -1, visit_stack, visited) != OK || \
// 		try_add_neighbor(index, 0, 1, visit_stack, visited) != OK || \
// 		try_add_neighbor(index, -1, 0, visit_stack, visited) != OK || \
// 		try_add_neighbor(index, 1, 0, visit_stack, visited) != OK)
// 		return (ERROR);
// 	return (OK);
// }

// t_status	foo(t_data *data)
// {
// 	bool	*visited;
// 	size_t	*visit_stack;
// 	t_tile	*current;

// 	// TODO: Maybe replace data->char_grid.width * data->char_grid.height
// 	// with something like sizeof(data->char_grid.cells) if it is 1D
// 	visited = ft_vector_new_reserved(sizeof(size_t), data->char_grid.width * data->char_grid.height);
// 	if (visited == NULL)
// 		return (ERROR);
// 	ft_bzero(visited, data->char_grid.width * data->char_grid.height);
// 	visit_stack = ft_vector_new(sizeof(size_t));
// 	if (visit_stack == NULL)
// 		return (ERROR);
// 	// TODO: Don't hardcode players[0] since the bonus supports several players
// 	current = &data->players[0].entity->tile;
// 	visited[get_index_from_xy(current->column, current->row, data)] = true;
// 	if (add_unvisited_neighbors(get_index_from_xy(current->column, current->row, data), &visit_stack, visited) != OK)
// 		return (ERROR);
// 	while (ft_vector_get_size(visit_stack) > 0)
// 	{
// 		current = ft_vector_back(visit_stack);
// 		if (add_unvisited_neighbors(get_index_from_xy(current->column, current->row, data), &visit_stack, visited) != OK)
// 			return (ERROR);
// 		ft_vector_pop_back(&visit_stack);
// 	}
// 	return (sl_set_error(SL_ERROR_NO_PATH));
// }

////////////////////////////////////////////////////////////////////////////////

t_status	check_valid_path(t_data *data)
{
	(void)data;
	// if (foo(data) != OK)
	// 	return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
