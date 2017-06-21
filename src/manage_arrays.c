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

void		*ezarray_get_index(const ARRAY ezarray, const UINT index)
{
	return (index < ezarray.length
		&& ezarray.data ? ezarray.data + index * ezarray.data_size : NULL);
}

BOOL		ezarray_is_signed(const ARRAY ezarray)
{
	return (!(ezarray.type & 0x100));
}

void		ezarray_realloc(ARRAY *ezarray, UINT new_length)
{
	ARRAY	locarray;

	locarray = *ezarray;
	locarray.length = new_length;
	locarray.total_size = locarray.length * locarray.data_size;
	locarray.data = realloc(locarray.data, locarray.total_size + 1);
	((char*)locarray.data)[locarray.total_size] = 0;
	*ezarray = locarray;
}
