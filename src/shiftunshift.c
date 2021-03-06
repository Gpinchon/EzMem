/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftunshift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 23:19:56 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/02 12:50:33 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

static inline void	ezarray_resize_shiftunshift(ARRAY *ezarray,
	UINT new_length)
{
	ARRAY	locarray;

	locarray = *ezarray;
	if (locarray.length == new_length)
		return ;
	if (locarray.reserved >= new_length)
	{
		locarray.length = new_length;
		locarray.total_size = locarray.length * locarray.data_size;
		((char*)locarray.data)[locarray.total_size] = 0;
		*ezarray = locarray;
		return ;
	}
	ezarray_realloc(ezarray, new_length);
}

void				ezarray_shift(ARRAY *ezarray)
{
	char	*head;
	char	*tail;
	ARRAY	locarray;

	locarray = *ezarray;
	if (locarray.length <= 1)
		return ;
	head = locarray.data;
	tail = locarray.data + locarray.total_size;
	while ((char*)locarray.data + locarray.data_size != tail)
	{
		*((char*)locarray.data) = *((char*)locarray.data + locarray.data_size);
		locarray.data++;
	}
	locarray.data = head;
	*ezarray = locarray;
	ezarray_resize_shiftunshift(ezarray, ezarray->length - 1);
}

void				ezarray_unshift(ARRAY *ezarray, void *element)
{
	char	*head;
	ARRAY	locarray;

	ezarray_resize_shiftunshift(ezarray, ezarray->length + 1);
	locarray = *ezarray;
	head = locarray.data;
	locarray.data = locarray.data + locarray.total_size;
	while ((char*)locarray.data != head)
	{
		*((char*)locarray.data) = *((char*)locarray.data - locarray.data_size);
		if (locarray.data - locarray.data_size == head)
			break ;
		locarray.data--;
	}
	locarray.data = head;
	if (element)
		while (locarray.data != head + locarray.data_size)
		{
			*((char*)locarray.data) = *((char*)element);
			locarray.data++;
			element++;
		}
	locarray.data = head;
	*ezarray = locarray;
}
