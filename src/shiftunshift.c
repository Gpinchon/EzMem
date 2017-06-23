/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftunshift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 23:19:56 by gpinchon          #+#    #+#             */
/*   Updated: 2016/10/26 00:45:41 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void	ezarray_shift(ARRAY *ezarray)
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
	ezarray_resize_dirty(ezarray, ezarray->length - 1);
}

void	ezarray_unshift(ARRAY *ezarray, void *element)
{
	char	*head;
	ARRAY	locarray;

	ezarray_resize_dirty(ezarray, ezarray->length + 1);
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
