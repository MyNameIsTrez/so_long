/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_print_error.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 13:20:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 16:55:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "../so_long.h"

////////////////////////////////////////////////////////////////////////////////

void	sl_print_error(void)
{
	char*const	sl_error_messages[] = {
	[SL_ERROR_FILE_HAS_INVALID_CHAR] = "The input map has an invalid character.",
	[SL_ERROR_INVALID_SCALE] = "The scale argument that was provided to the program is invalid.",
	[SL_ERROR_MLX42] = "MLX42 reported something went wrong.",
	[SL_ERROR_TOO_MANY_PLAYERS] = "There are too many player characters in the input map.",
	};

	ft_print("Error: ");
	ft_putendl(sl_error_messages[sl_get_error()]);
}

////////////////////////////////////////////////////////////////////////////////
