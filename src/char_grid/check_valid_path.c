/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_valid_path.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/10 13:48:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 12:47:23 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "private/check_valid_path/sl_private_check_valid_path.h"

////////////////////////////////////////////////////////////////////////////////

t_status	try_add_neighbor(t_heading heading, t_tile *tile, t_tile ***visit_stack, bool *visited, t_data *data)
{
	t_i32	column;
	t_i32	row;
	size_t	index;
	t_tile	*neighbor_tile;
	t_u8	neighbor_tile_character;

	// TODO: Make a function that returns t_status and fills a pointer to index?
	column = sl_get_heading_column(heading, tile, data);
	row = sl_get_heading_row(heading, tile, data);
	if (sl_out_of_bounds(column, row, data))
		return (OK);
	index = sl_get_index((size_t)column, (size_t)row, data);

	if (visited[index])
		return (OK);
	neighbor_tile = &data->tile_grid.cells[index];
	neighbor_tile_character = neighbor_tile->tile_kind->character;
	if (!ft_chr_in_str(neighbor_tile_character, WALKABLE_CHARACTERS ENTITY_CHARACTERS))
		return (OK);
	if (ft_vector_push(visit_stack, &neighbor_tile) != OK)
		return (ERROR);
	visited[index] = true;
	return (OK);
}

t_status	add_unvisited_neighbors(t_tile *tile, t_tile ***visit_stack, bool *visited, t_data *data)
{
	t_iterator	it;

	ft_init_it(&it);
	while (sl_iterate_headings(&it, data) != FINISHED)
		if (try_add_neighbor(data->it.heading, tile, visit_stack, visited, data) != OK)
			return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////

t_status	sl_check_valid_path(t_data *data)
{
	bool	*visited;
	t_tile	**visit_stack;
	t_tile	*current;

	// TODO: Maybe replace data->char_grid.width * data->char_grid.height
	// with something like sizeof(data->char_grid.cells) if it is 1D
	visited = ft_vector_new_reserved(sizeof(bool), data->char_grid.width * data->char_grid.height);
	if (visited == NULL)
		return (ERROR);
	ft_bzero(visited, data->char_grid.width * data->char_grid.height * sizeof(bool));
	visit_stack = ft_vector_new(sizeof(t_tile *));
	if (visit_stack == NULL)
		return (ERROR);
	// TODO: Don't hardcode players[0] since the bonus supports several players?
	current = &data->players[0].entity->tile;
	visited[current->index] = true;
	if (add_unvisited_neighbors(current, &visit_stack, visited, data) != OK)
		return (ERROR);
	while (ft_vector_get_size(visit_stack) > 0)
	{
		current = *(t_tile **)ft_vector_back(visit_stack);
		ft_vector_pop_back(&visit_stack);
		if (current->tile_kind->character == MAP_EXIT_CHARACTER)
			return (OK);
		if (add_unvisited_neighbors(current, &visit_stack, visited, data) != OK)
			return (ERROR);
	}
	return (sl_set_error(SL_ERROR_NO_PATH));
}

////////////////////////////////////////////////////////////////////////////////
