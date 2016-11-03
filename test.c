/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 00:41:03 by gpinchon          #+#    #+#             */
/*   Updated: 2016/11/03 15:44:32 by gpinchon         ###   ########.fr       */
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

void	print_int_array(ARRAY array)
{
	UINT	i = 0;
	int		*index;

	while (i < array.length)
	{
		index = array_get_index(array, i);
		printf("\tindex %i of %i equals : %i\n", i, array.length - 1, *index);
		i++;
	}
}

int main()
{
	ARRAY	array;
	STRING	string;
	int		*i;
	int		new_value;
	t_vec3	*vector;

	printf("Creating an array of size 2000\n");
	array = new_array(signed_int, 2000);
	i = array_get_index(array, 0);
	printf("address 0 of 1999 : %p\n", i);
	*(&i[0]) = 10;
	*(&i[1]) = 20;
	*(&i[2]) = 30;
	*(&i[3]) = 40;
	*(&i[4]) = 50;
	i = array_get_index(array, 1);
	printf("address 1 of 1999 : %p\n", i);
	i = array_get_index(array, 2000);
	printf("address 2000 of 1999 : %p\n", i);
	i = array_get_index(array, 40000);
	printf("address 40000 of 1999 : %p\n", i);
	i = array_get_index(array, 0);
	printf("index 0 of 1999 equals : %i\n", *i);
	i = array_get_index(array, 1);
	printf("index 1 of 1999 equals : %i\nreallocating array\n", *i);
	array_realloc(&array, 5);
	print_int_array(array);
	printf("pushing array\n");
	new_value = 15;
	array_push(&array, &new_value);
	print_int_array(array);
	printf("shifting array\n");
	array_shift(&array);
	print_int_array(array);
	printf("popping array\n");
	array_pop(&array);
	print_int_array(array);
	printf("unshifting array\n");
	new_value = 42;
	array_unshift(&array, &new_value);
	print_int_array(array);
	printf("%s\n", (string = new_string("This is a string created using ezmem and returned using .tostring")).tostring);
	printf("Cleaning...\n");
	destroy_array(&array);
	destroy_string(&string);
	printf("Creating custom sized array...\n");
	array = new_array_dirty(other, 2000, sizeof(t_vec3));
	vector = array_get_index(array, 0);
	*(vector) = (t_vec3){1, 2, 3};
	printf("index 0 of 1999 : %p\nvalues %f, %f, %f\n", vector, vector->x, vector->y, vector->z);
	vector = array_get_index(array, 1);
	printf("index 1 of 1999 : %p\n", vector);
	vector = array_get_index(array, 2000);
	printf("index 2000 of 1999 : %p\n", vector);
	printf("Cleaning again...\n");
	destroy_array(&array);
	printf("Creating array of type 'other' with no specified size (UNDEFINED BEHAVIOR, DON'T DO THIS !!!)...\n");
	array = new_array(other, 2000);
	printf("array data_size : %u\n", array.data_size);
	i = array_get_index(array, 500);
	printf("index 500 of 1999 : %p\n", i);
	printf("Cleaning again...\n");
	destroy_array(&array);
	return (0);
}