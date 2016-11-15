/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:45:14 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/15 18:56:21 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void	ezlink_append(LINK *chain, LINK *element)
{
	if (chain->next)
		ezlink_append(chain->next, element);
	chain->next = element;
	element->prev = chain;
}
