/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_temporary.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 13:45:31 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/05 15:26:42 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef SL_TEMPORARY_H
# define SL_TEMPORARY_H

////////////////////////////////////////////////////////////////////////////////

// This struct is used for Temporary data storage. Used by iterators.
typedef struct s_t
{
	uint32_t	frame_index;
	uint32_t	row_index;
	uint32_t	column_index;
	t_grid		char_grid;
}	t_t;

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
