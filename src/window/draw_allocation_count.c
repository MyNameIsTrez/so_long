/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_allocation_count.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/15 15:29:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/15 15:57:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

#include "../../submodules/MLX42/src/font/font.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_draw_allocation_count(t_data *data)
{
	static mlx_image_t	*allocations_count_image;
	char				*allocation_count_string;
	char				*allocation_count_string_full;

	if (allocations_count_image != NULL)
		mlx_delete_image(data->mlx, allocations_count_image);
	allocation_count_string = ft_itoa((t_i32)ft_get_allocation_count());
	if (allocation_count_string == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	allocation_count_string_full = ft_strjoin("Allocation count: ", allocation_count_string);
	ft_free(&allocation_count_string);
	if (allocation_count_string_full == NULL)
	{
		sl_cleanup(data);
		sl_print_all_errors();
		return ;
	}
	allocations_count_image = mlx_put_string(data->mlx, allocation_count_string_full, 0, FONT_HEIGHT); // TODO: Should this be checked for any error?
	ft_free(&allocation_count_string_full);
}

////////////////////////////////////////////////////////////////////////////////
