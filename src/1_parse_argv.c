/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   1_parse_argv.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:27:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/23 16:00:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

STATIC bool	grid_has_invalid_character(t_grid *grid)
{
	size_t	y;
	size_t	x;
	char	chr;

	y = 0;
	while (y < grid->height)
	{
		x = 0;
		while (x < grid->width)
		{
			chr = grid->cells[y][x];
			if (!ft_chr_in_str(chr, MAP_CHARACTERS))
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

STATIC t_success	verify_argc(int argc)
{
	if (argc <= 1)
		return (ft_set_error(ERROR_TOO_FEW_ARGS));
	if (argc >= 4)
		return (ft_set_error(ERROR_TOO_MANY_ARGS));
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////

t_success	sl_parse_argv(int argc, char **argv, t_data *data)
{
	char	*filename;

	if (verify_argc(argc) != SUCCESS)
		return (ft_get_error());
	filename = argv[1];
	if (ft_read_grid_from_file(&data->grid, filename) != SUCCESS)
		return (ft_get_error());
	if (grid_has_invalid_character(&data->grid))
		return (ERROR_FILE_HAS_INVALID_CHAR);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
