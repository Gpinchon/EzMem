/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:31:43 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/15 20:23:11 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>
#include <stdarg.h>

LINK		*new_ezlink(const TYPE datatype, UINT length, ...)
{
	LINK	*ezlink;
	va_list	argptr;

	ezlink = malloc(sizeof(LINK));
	if ((datatype & 0x00F) >= 4)
	{
		va_start(argptr, length);
		ezlink->data = new_ezarray(datatype, length, va_arg(argptr, UINT));
	}
	else
		ezlink->data = new_ezarray(datatype, length);
	ezlink->next = ezlink->prev = NULL;
	return (ezlink);
}

LINK		*new_ezlink_dirty(const TYPE datatype, UINT length, ...)
{
	LINK	*ezlink;
	va_list	argptr;

	ezlink = malloc(sizeof(LINK));
	if ((datatype & 0x00F) >= 4)
	{
		va_start(argptr, length);
		ezlink->data = new_ezarray_dirty(datatype, length, va_arg(argptr, UINT));
	}
	else
		ezlink->data = new_ezarray_dirty(datatype, length);
	ezlink->next = ezlink->prev = NULL;
	return (ezlink);
}
