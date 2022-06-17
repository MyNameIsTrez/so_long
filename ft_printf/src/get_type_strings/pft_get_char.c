/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/05 15:58:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

t_success	pft_get_char(va_list arg_ptr, t_options *options)
{
	char const	chr = (char)va_arg(arg_ptr, int);

	if (ft_str_assign(&options->parts.base_str, ft_char_to_str(chr)) != SUCCESS)
		return (ERROR);
	if (ft_empty_str_assign(&options->parts.prefix) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
