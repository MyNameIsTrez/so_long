/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_collectibles.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 16:36:48 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/24 12:34:54 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_COLLECTIBLES_H
# define SL_COLLECTIBLES_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_collectible	t_collectible;

////////////////////////////////////////////////////////////////////////////////

void		sl_collect_collectible(t_collectible *collectible, t_data *data);
t_status	sl_instantiate_collectibles(t_data *data);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
