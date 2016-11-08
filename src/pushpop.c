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

void	array_push(ARRAY *array, void *element)
{
	char	*seeker;
	char	*tail;

	array_realloc(array, array->length + 1);
	if (!element)
		return;
	tail = array->data + array->total_size;
	seeker = array_get_index(*array, array->length - 1);
	while (seeker != tail)
	{
		*((char*)seeker) = *((char*)element);
		(element)++;
		(seeker)++;
	}
}

void	array_pop(ARRAY *array)
{
	array_realloc(array, array->length - 1);
}