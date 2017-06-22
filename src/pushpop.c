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
	char	*seeker;
	char	*tail;
	ARRAY	locarray;

	locarray = *ezarray;
	ezarray_realloc(&locarray, locarray.length + 1);
	if (!element)
		return ;
	tail = locarray.data + locarray.total_size;
	seeker = ezarray_get_index(locarray, locarray.length - 1);
	while (seeker != tail)
	{
		*((char*)seeker) = *((char*)element);
		(element)++;
		(seeker)++;
	}
	*ezarray = locarray;
}

void	ezarray_pop(ARRAY *ezarray)
{
	ezarray_realloc(ezarray, ezarray->length - 1);
}
