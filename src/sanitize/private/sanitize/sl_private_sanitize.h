/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_sanitize.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 17:35:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/05 22:17:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_SANITIZE_H
# define SL_PRIVATE_SANITIZE_H

////////////////////////////////////////////////////////////////////////////////

t_status	sanitize_argc(t_i32 argc);
t_status	sanitize_argv(t_i32 argc, char **argv);
t_status	sanitize_defines(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
