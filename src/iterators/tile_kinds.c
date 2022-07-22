/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tile_kinds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 17:54:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 17:39:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_iterator_status	resettable_iterate_tile_kinds(t_data *data,
								bool reset)
{
	static t_list	*lst;

	if (reset)
	{
		lst = data->tile_kinds;
		return (RESET);
	}
	while (lst != NULL)
	{
		data->it.tile_kind = lst->content;
		lst = lst->next;
		return (LOOPED);
	}
	sl_reset_iterate_tile_kinds(data);
	return (FINISHED);
}

////////////////////////////////////////////////////////////////////////////////

t_iterator_status	sl_iterate_tile_kinds(t_data *data)
{
	return (resettable_iterate_tile_kinds(data, false));
}

void	sl_reset_iterate_tile_kinds(t_data *data)
{
	resettable_iterate_tile_kinds(data, true);
}

////////////////////////////////////////////////////////////////////////////////
