/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:38:53 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/14 15:49:55 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>

void	ezforeach(ARRAY array, EZCALLBACK)
{
	UINT	ui;

	ui = 0;
	if (callback)
		while (ui < array.length)
		{
			callback(ezarray_get_index(array, ui));
			ui++;
		}
}