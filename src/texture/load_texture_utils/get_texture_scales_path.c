/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_texture_scales_path.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 18:49:53 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 18:49:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "so_long.h"

////////////////////////////////////////////////////////////////////////////////

char	*get_texture_scales_path(void)
{
	return (TEXTUREPACKS_PATH TEXTUREPACK TEXTURE_SCALES_DIR);
}

////////////////////////////////////////////////////////////////////////////////
