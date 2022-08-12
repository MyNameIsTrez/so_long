/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 16:21:33 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 18:22:15 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

// TODO: remove
// __attribute__((deconstructor))
// __attribute__((destructor))
void	check_leaks(void)
{
	ft_putendl("");
	system("leaks -q so_long");
}

////////////////////////////////////////////////////////////////////////////////

t_i32	main(t_i32 argc, char **argv)
{
	t_data	data;

	atexit(check_leaks); // TODO: Remove!
	if (sl_init(argc, argv, &data) != OK)
	{
		sl_cleanup(&data);
		sl_print_all_errors();
		return (EXIT_FAILURE);
	}
	// exit(EXIT_FAILURE);
	mlx_loop(data.mlx);
	sl_cleanup(&data);
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
