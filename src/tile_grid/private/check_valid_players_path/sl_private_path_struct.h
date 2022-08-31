/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_private_path_struct.h                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 16:13:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/30 16:13:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_PRIVATE_PATH_STRUCT_H
# define SL_PRIVATE_PATH_STRUCT_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_path
{
	t_tile	**visit_stack;
	t_tile	*current;
	bool	exit_seen;
	size_t	collectibles_seen;
}	t_path;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////