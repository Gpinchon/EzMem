/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushpop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:01:29 by gpinchon          #+#    #+#             */
/*   Updated: 2016/10/25 23:54:06 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void	ezarray_push(ARRAY *ezarray, void *element)
{
	ARRAY	locarray;

	locarray = *ezarray;
	ezarray_resize_dirty(&locarray, locarray.length + 1);
	if (!element)
		return ;
	memmove(locarray.data + (locarray.length - 1) * locarray.data_size,
		element, locarray.data_size);
	*ezarray = locarray;
}

void	ezarray_pop(ARRAY *ezarray)
{
	ezarray_resize_dirty(ezarray, ezarray->length - 1);
}
