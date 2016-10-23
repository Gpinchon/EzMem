/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arrays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 00:20:43 by gpinchon          #+#    #+#             */
/*   Updated: 2016/10/23 01:59:08 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>
#include <data_size.h>
#include <stdarg.h>

t_array		new_array(const TYPE datatype, UINT length, ...)
{
	t_array	array;
	va_list	argptr;

	array.type = datatype;
	array.length = length;
	if ((datatype & 0x00F) < 4)
		array.data_size = g_datasize[(datatype & 0x0F0) >> 4][datatype & 0x00F];
	else
	{
		va_start(argptr, 0);
		array.data_size = va_arg(argptr, UINT);
		va_end(argptr);
	}
	array.total_size = array.length * array.data_size + 1;
	array.data = malloc(array.total_size);
	while (length)
	{
		((char*)array.data)[length * array.data_size] = 0;
		length--;
	}
	return (array);
}

t_array		new_array_dirty(const TYPE datatype, UINT length, ...)
{
	t_array	array;
	va_list	argptr;

	array.type = datatype;
	array.length = length;
	if ((datatype & 0x00F) < 4)
		array.data_size = g_datasize[(datatype & 0x0F0) >> 4][datatype & 0x00F];
	else
	{
		va_start(argptr, 0);
		array.data_size = va_arg(argptr, UINT);
		va_end(argptr);
	}
	array.total_size = array.length * array.data_size + 1;
	array.data = malloc(array.total_size);
	((char*)array.data)[array.total_size + 1] = 0;
	return (array);
}

t_string	new_string(const char *src)
{
	t_string str;
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
