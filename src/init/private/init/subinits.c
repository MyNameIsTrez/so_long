/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   subinits.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 13:51:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/22 16:08:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_subinits(t_data *data)
{
	static const t_subinit	subinit_table[] = {
		sl_instantiate_background,
		sl_load_texture,
		sl_instantiate_tile_kinds,
		sl_initialize_tile_kinds_colors,
		sl_instantiate_tile_grid,
		sl_instantiate_entities,
		sl_initialize_players,
		sl_instantiate_monsters,
		sl_instantiate_collectibles,
		sl_check_valid_path,
	};
	size_t					subinit_count;
	static t_iterator		it;

	subinit_count = sizeof(subinit_table) / sizeof(*subinit_table);
	it = ft_get_count_iterator(subinit_count);
	while (ft_iterate(&it) != FINISHED)
		if (subinit_table[it.current](data) != OK)
			return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
