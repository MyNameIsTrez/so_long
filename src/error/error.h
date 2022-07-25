/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 16:15:18 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/25 11:34:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef ERROR_H
# define ERROR_H

////////////////////////////////////////////////////////////////////////////////

typedef enum e_sl_error
{
	SL_OK,
	SL_ERROR_FILE_HAS_INVALID_CHAR,
	SL_ERROR_INVALID_SCALE,
	SL_ERROR_MLX42,
	SL_ERROR_TOO_MANY_PLAYERS,
}	t_sl_error;

////////////////////////////////////////////////////////////////////////////////

t_status	sl_any_error(void);
t_sl_error	*sl_get_error_ptr(void);
t_sl_error	sl_get_error(void);
void		sl_print_all_errors(void);
void		sl_print_error(void);
t_status	sl_set_error(t_sl_error sl_error);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
