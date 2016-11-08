/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arrays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 00:20:43 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/03 16:03:53 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>
#include <data_size.h>
#include <stdarg.h>

static void	allocate_array(ARRAY *array, const TYPE datatype, UINT length, va_list argptr)
{
	if ((datatype & 0x00F) < 4)
		array->data_size = g_datasize[(datatype & 0x0F0) >> 4][datatype & 0x00F];
	else
	{
		array->data_size = va_arg(argptr, UINT);
		va_end(argptr);
	}
	array->type = datatype;
	array->length = length;
	array->total_size = array->length * array->data_size;
	array->data = malloc(array->total_size + 1);
}

ARRAY		new_array(const TYPE datatype, UINT length, ...)
{
	ARRAY	array;
	va_list	argptr;

	if ((datatype & 0x00F) >= 4)
		va_start(argptr, length);
	allocate_array(&array, datatype, length, argptr);
	length = array.length;
	while (length)
	{
		((char*)array.data)[array.total_size] = 0;
		length--;
	}
	return (array);
}

ARRAY		new_array_dirty(const TYPE datatype, UINT length, ...)
{
	ARRAY	array;
	va_list	argptr;

	if ((datatype & 0x00F) >= 4)
		va_start(argptr, length);
	allocate_array(&array, datatype, length, argptr);
	((char*)array.data)[array.total_size] = 0;
	return (array);
}

STRING	new_string(const char *src)
{
	STRING str;
	const char	*ptr;
	void		*data;

	ptr = src;
	str.length = 0;
	while (*src)
	{
		str.length++;
		src++;
	}
	src = ptr;
	str.array = new_array_dirty(CHAR, str.length);
	str.tostring = (char *)str.array.data;
	data = str.array.data;
	while (*src)
	{
		*((char*)str.array.data) = *(src);
		src++;
		str.array.data += str.array.data_size;
	}
	src = ptr;
	str.array.data = data;
	return (str);
}
