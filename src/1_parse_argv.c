/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   1_parse_argv.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:27:09 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/22 14:12:03 by sbos          ########   odam.nl         */
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
			if (!ft_chr_in_str(MAP_CHARACTERS, chr))
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

////////////////////////////////////////////////////////////////////////////////

t_success	parse_argv(int argc, char **argv, t_grid *grid)
{
	char	*filename;

	if (argc != 2) // TODO: Should it only every work for argc == 2?
		return (ERROR);
	filename = argv[1];
	if (ft_read_grid_from_file(grid, filename) != SUCCESS
		|| grid_has_invalid_character(grid))
		return (ERROR);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
