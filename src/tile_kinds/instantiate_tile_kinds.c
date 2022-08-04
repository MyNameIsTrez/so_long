/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instantiate_tile_kinds.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 15:58:00 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/04 15:04:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "instantiate_tile_kinds_utils/add_tile_kind/sl_instantiate_tile_kinds_utils_add_tile_kind.h"

////////////////////////////////////////////////////////////////////////////////

t_status	sl_instantiate_tile_kinds(t_data *data)
{
	data->tile_kinds = ft_vector_new(sizeof(t_tile_kind));
	if (add_empty_space_tile_kind(data) != OK)
		return (ERROR);
	if (add_wall_tile_kind(data) != OK)
		return (ERROR);
	if (add_collectible_tile_kind(data) != OK)
		return (ERROR);
	if (add_map_exit_tile_kind(data) != OK)
		return (ERROR);
	if (add_monster_tile_kind(data) != OK)
		return (ERROR);
	if (add_player_1_tile_kind(data) != OK)
		return (ERROR);
	if (add_player_2_tile_kind(data) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
