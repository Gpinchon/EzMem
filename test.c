/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 00:41:03 by gpinchon          #+#    #+#             */
/*   Updated: 2016/10/25 22:09:58 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>
#include <stdio.h>

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

int main()
{
	ARRAY	array;
	STRING	string;
	int		*i;
	t_vec3	*vector;

	printf("Creating an array of size 2000\n");
	array = new_array(signed_int, 2000);
	i = get_array_index(array, 0);
	printf("index 0 of 1999 : %p\n", i);
	*(i) = 10;
	i = get_array_index(array, 1);
	printf("index 1 of 1999 : %p\n", i);
	*(i) = 20;
	i = get_array_index(array, 2000);
	printf("index 2000 of 1999 : %p\n", i);
	i = get_array_index(array, 40000);
	printf("index 40000 of 1999 : %p\n", i);
	i = get_array_index(array, 0);
	printf("index 0 of 1999 equals : %i\n", *i);
	i = get_array_index(array, 1);
	printf("index 1 of 1999 equals : %i\n", *i);
	printf("reallocating array\n");
	realloc_array(&array, 2);
	i = get_array_index(array, 0);
	printf("index 0 of 1 equals : %i\n", *i);
	i = get_array_index(array, 1);
	printf("index 1 of 1 equals : %i\n", *i);

	printf("%s\n", (string = new_string("This is a string created using ezmem and returned using .tostring")).tostring);

	printf("Cleaning...\n");
	destroy_array(&array);
	destroy_string(&string);

	printf("Creating custom sized array...\n");
	array = new_array_dirty(other, 2000, sizeof(t_vec3));
	vector = get_array_index(array, 0);
	printf("index 0 of 1999 : %p\n", vector);
	vector = get_array_index(array, 1);
	printf("index 1 of 1999 : %p\n", vector);
	vector = get_array_index(array, 2000);
	printf("index 2000 of 1999 : %p\n", vector);
	vector = get_array_index(array, 40000);
	printf("index 40000 of 1999 : %p\n", vector);
	printf("Cleaning again...\n");
	destroy_array(&array);
	return (0);
}