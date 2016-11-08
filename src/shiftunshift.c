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

void	array_shift(ARRAY *array)
{
	char	*head;
	char	*tail;

	if (array->length <= 1)
		return ;
	head = array->data;
	tail = array->data + array->total_size;
	while ((char*)array->data + array->data_size != tail)
	{
		*((char*)array->data) = *((char*)array->data + array->data_size);
		array->data++;
	}
	array->data = head;
	array_realloc(array, array->length - 1);
}

void	array_unshift(ARRAY *array, void *element)
{
	char	*head;

	array_realloc(array, array->length + 1);
	head = array->data;
	array->data = array->data + array->total_size;
	while ((char*)array->data != head)
	{
		*((char*)array->data) = *((char*)array->data - array->data_size);
		if (array->data - array->data_size == head)
			break ;
		array->data--;
	}
	array->data = head;
	if (element)
		while (array->data != head + array->data_size)
		{
			*((char*)array->data) = *((char*)element);
			array->data++;
			element++;
		}
	array->data = head;
}
