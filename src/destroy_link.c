/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:40:25 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/15 18:55:59 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void	destroy_ezlink(LINK *ezlink)
{
	destroy_ezarray(&ezlink->data);
	if (ezlink->prev)
		ezlink->prev->next = ezlink->next;
	if (ezlink->next)
		ezlink->next->prev = ezlink->prev;
}