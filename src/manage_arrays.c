/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 00:21:55 by gpinchon          #+#    #+#             */
/*   Updated: 2016/10/23 00:22:04 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void		*get_array_index(const ARRAY array, const UINT index)
{
	return (index < array.length
		&& array.data ? array.data + index * array.data_size : NULL);
}

BOOL		array_is_signed(const ARRAY array)
{
	return (!(array.type & 0x100));
}
