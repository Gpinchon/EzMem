/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ezmemalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:07:41 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/02 12:49:19 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void	ezarray_realloc(ARRAY *ezarray, UINT new_length)
{
	ARRAY	locarray;

	locarray = *ezarray;
	locarray.length = new_length;
	locarray.reserved = new_length;
	locarray.total_size = locarray.length * locarray.data_size;
	locarray.data = realloc(locarray.data, locarray.total_size + 1);
	((char*)locarray.data)[locarray.total_size] = 0;
	*ezarray = locarray;
}

void	*ezmemalloc(UINT size)
{
	char	*memptr;

	if (!(memptr = malloc(size)))
		return (NULL);
	while (size)
	{
		size--;
		memptr[size] = 0;
	}
	return (memptr);
}

void	ezarray_reserve(ARRAY *ezarray, UINT new_length)
{
	ARRAY	locarray;

	locarray = *ezarray;
	if (locarray.reserved < new_length)
	{
		locarray.reserved = new_length;
		locarray.data = realloc(locarray.data,
			locarray.reserved * locarray.data_size + 1);
		*ezarray = locarray;
	}
}
