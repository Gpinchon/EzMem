/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 00:21:55 by gpinchon          #+#    #+#             */
/*   Updated: 2016/10/26 00:20:47 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void		*array_get_index(const ARRAY array, const UINT index)
{
	return (index < array.length
		&& array.data ? array.data + index * array.data_size : NULL);
}

BOOL		array_is_signed(const ARRAY array)
{
	return (!(array.type & 0x100));
}

void		array_realloc(ARRAY *array, UINT new_length)
{
	array->length = new_length;
	array->total_size = array->length * array->data_size;
	array->data = realloc(array->data, array->total_size + 1);
	((char*)array->data)[array->total_size] = 0;
}
