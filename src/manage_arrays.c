/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 00:21:55 by gpinchon          #+#    #+#             */
/*   Updated: 2016/10/23 02:01:45 by gpinchon         ###   ########.fr       */
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

ARRAY		realloc_array(ARRAY array, UINT new_length)
{
	array.length = new_length;
	array.total_size = array.length * array.data_size + 1;
	array.data = realloc(array.data, array.total_size);
	((char*)array.data)[array.total_size + 1] = 0;
	return (array);
}
