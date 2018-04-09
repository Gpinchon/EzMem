/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:34:11 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/09 17:37:56 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void		ezarray_erase(ARRAY *ezarray, UINT from, UINT to)
{
	UINT	distance;
	void	*from_it;
	void	*to_it;

	if (to < from || to >= ezarray->length)
		return ;
	to++;
	distance = (to - from);
	from_it = ezarray_get_index(*ezarray, from);
	to_it = ezarray_get_index(*ezarray, to);
	if (distance + to >= ezarray->length)
		distance -= (distance + to) - ezarray->length;
	memcpy(from_it, to_it, ezarray->data_size * distance);
	ezarray->length -= (to - from);
}

void		ezarray_erase_one(ARRAY *ezarray, UINT erase)
{
	if (erase + 1 >= ezarray->length)
	{
		ezarray->length--;
		return ;
	}
	void	*from_it = ezarray_get_index(*ezarray, erase);
	void	*to_it = ezarray_get_index(*ezarray, erase + 1);
	memcpy(from_it, to_it, ezarray->data_size);
	ezarray->length--;
}
