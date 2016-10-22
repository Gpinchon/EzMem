/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 00:21:06 by gpinchon          #+#    #+#             */
/*   Updated: 2016/10/23 00:21:29 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void		destroy_array(ARRAY *array)
{
	if (array->total_size)
		free(array->data);
	*array = (ARRAY){0, 0x000, 0, 0, NULL};
}

void		destroy_string(STRING *str)
{
	destroy_array(&str->array);
	str->length = 0;
	str->tostring = NULL;
}
