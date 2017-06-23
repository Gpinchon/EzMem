/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 00:21:55 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/14 14:45:30 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void	*ezarray_get_index(const ARRAY ezarray, const UINT index)
{
	return (index < ezarray.length
		&& ezarray.data ? ezarray.data + index * ezarray.data_size : NULL);
}

BOOL	ezarray_is_signed(const ARRAY ezarray)
{
	return (!(ezarray.type & 0x100));
}

void	ezarray_shrink(ARRAY *ezarray)
{
	ARRAY	locarray;

	locarray = *ezarray;
	if (locarray.length < locarray.reserved)
		ezarray_realloc(ezarray, locarray.length);
}

void	ezarray_resize(ARRAY *ezarray, UINT new_length)
{
	ARRAY	locarray;

	locarray = *ezarray;
	if (locarray.length == new_length)
		return ;
	if (locarray.reserved >= new_length)
	{
		if (new_length > locarray.length)
			memset(locarray.data + locarray.total_size, 0, (new_length - locarray.length)* locarray.data_size);
		locarray.length = new_length;
		locarray.total_size = locarray.length * locarray.data_size;
		((char*)locarray.data)[locarray.total_size] = 0;
		*ezarray = locarray;
		return ;
	}
	ezarray_realloc(ezarray, new_length);
}

void	ezarray_resize_dirty(ARRAY *ezarray, UINT new_length)
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
