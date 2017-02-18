/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ezmemalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:07:41 by gpinchon          #+#    #+#             */
/*   Updated: 2017/02/19 00:01:53 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

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
