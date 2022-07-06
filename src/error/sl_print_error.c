/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_print_error.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 13:20:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/06 14:59:03 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_print_error(void)
{
	char*const	sl_error_messages[] = {
		"",
		"The input map has an invalid character.",
		"The scale argument that was provided to the program is invalid.",
		"MLX42 reported something went wrong.",
		"There are too many player characters in the input map.",
	};

	ft_print("Error: ");
	ft_print(sl_error_messages[sl_get_error()]);
}

////////////////////////////////////////////////////////////////////////////////
