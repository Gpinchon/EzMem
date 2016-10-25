/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushpop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:01:29 by gpinchon          #+#    #+#             */
/*   Updated: 2016/10/25 23:09:36 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>
#include <string.h>
#include <stdio.h>

void	array_push(ARRAY *array, void *element)
{
	char	*head;
	char	*tail;

	realloc_array(array, array->length + 1);
	if (!element)
		return;
	head = array->data;
	tail = head + array->total_size;
	array->data = get_array_index(*array, array->length - 1);
	while (array->data != tail)
	{
		*((char*)array->data) = *((char*)element);
		(element)++;
		(array->data)++;
	}
	array->data = head;
}

void	array_pop(ARRAY *array)
{
	realloc_array(array, array->length - 1);
}