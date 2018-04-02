/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushpop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:01:29 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/02 12:49:37 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

static inline void	ezarray_resize_pushpop(ARRAY *ezarray, UINT new_length)
{
	ARRAY	locarray;

	locarray = *ezarray;
	if (locarray.length == new_length)
		return ;
	if (locarray.reserved > new_length)
	{
		locarray.length = new_length;
		locarray.total_size = locarray.length * locarray.data_size;
		((char*)locarray.data)[locarray.total_size] = 0;
		*ezarray = locarray;
		return ;
	}
	ezarray_reserve(ezarray, new_length * FASTPUSH);
	ezarray_resize(ezarray, new_length);
}

void				ezarray_push(ARRAY *ezarray, void *element)
{
	ARRAY	locarray;

	locarray = *ezarray;
	ezarray_resize_pushpop(&locarray, locarray.length + 1);
	if (!element)
		return ;
	memmove(locarray.data + (locarray.length - 1) * locarray.data_size,
		element, locarray.data_size);
	*ezarray = locarray;
}

void				ezarray_pop(ARRAY *ezarray)
{
	ezarray_resize_pushpop(ezarray, ezarray->length - 1);
}
