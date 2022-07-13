/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 17:31:01 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/07 16:13:48 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_cleanup(t_data *data)
{
	if (data->texture.data != NULL)
		mlx_delete_texture(data->texture.data);
}

////////////////////////////////////////////////////////////////////////////////