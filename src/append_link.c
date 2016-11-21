/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:45:14 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/21 11:46:52 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void	ezlink_append(LINK *chain, LINK *element)
{
	if (chain && chain->next)
		ezlink_append(chain->next, element);
	else if (chain && element)
	{
		chain->next = element;
		element->prev = chain;
	}
}
