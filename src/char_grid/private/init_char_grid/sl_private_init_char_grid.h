/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_init_char_grid.h                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 19:33:14 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 13:54:53 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_INIT_CHAR_GRID_H
# define SL_PRIVATE_INIT_CHAR_GRID_H

////////////////////////////////////////////////////////////////////////////////

t_status	check_duplicate_start_or_exit_character(t_data *data);
t_status	check_invalid_character(t_data *data);
t_status	has_basic_characters(t_data *data);
bool		map_is_not_enclosed(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
