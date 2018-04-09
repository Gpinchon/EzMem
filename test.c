/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 00:41:03 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/09 17:31:03 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ezmem.h>
#include <stdio.h>
#include <time.h>

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

void	print_int_ezarray(ARRAY ezarray)
{
	UINT	i = 0;
	int		*index;

	while (i < ezarray.length)
	{
		index = ezarray_get_index(ezarray, i);
		printf("\tindex %i of %i equals : %i\n", i, ezarray.length - 1, *index);
		i++;
	}
}

clock_t	performance_test_reserve(unsigned operation_count)
{
	unsigned	i;
	ARRAY		ezarray;
	clock_t		start;

	i = 0;
	ezarray = new_ezarray(UNSIGNED|INT, 0);
	ezarray_reserve(&ezarray, operation_count);
	start = clock();
	while (i < operation_count)
	{
		ezarray_push(&ezarray, &i);
		i++;
	}
	destroy_ezarray(&ezarray);
	return (clock() - start);
}

clock_t	performance_test_woreserve(unsigned operation_count)
{
	unsigned	i;
	ARRAY		ezarray;
	clock_t		start;

	i = 0;
	ezarray = new_ezarray(UNSIGNED|INT, 0);
	start = clock();
	while (i < operation_count)
	{
		ezarray_push(&ezarray, &i);
		i++;
	}
	destroy_ezarray(&ezarray);
	return (clock() - start);
}

int main()
{
	ARRAY	ezarray;
	LINK	*ezlink;
	STRING	ezstring;
	int		*i;
	int		new_value;
	t_vec3	*vector;

	printf("Creating an ezarray of size 2000\n");
	ezarray = new_ezarray(signed_int, 2000);
	i = ezarray_get_index(ezarray, 0);
	printf("address 0 of 1999 : %p\n", i);
	*(&i[0]) = 10;
	*(&i[1]) = 20;
	*(&i[2]) = 30;
	*(&i[3]) = 40;
	*(&i[4]) = 50;
	i = ezarray_get_index(ezarray, 1);
	printf("address 1 of 1999 : %p\n", i);
	i = ezarray_get_index(ezarray, 2000);
	printf("address 2000 of 1999 : %p (expecting NULL)\n", i);
	i = ezarray_get_index(ezarray, 0);
	printf("index 0 of 1999 equals : %i\n", *i);
	i = ezarray_get_index(ezarray, 1);
	printf("index 1 of 1999 equals : %i\nReallocating ezarray\n", *i);
	ezarray_realloc(&ezarray, 5);
	print_int_ezarray(ezarray);
	printf("pushing ezarray\n");
	new_value = 60;
	ezarray_push(&ezarray, &new_value);
	print_int_ezarray(ezarray);
	printf("shifting ezarray\n");
	ezarray_shift(&ezarray);
	print_int_ezarray(ezarray);
	printf("popping ezarray\n");
	ezarray_pop(&ezarray);
	print_int_ezarray(ezarray);
	printf("unshifting ezarray\n");
	new_value = 10;
	ezarray_unshift(&ezarray, &new_value);
	print_int_ezarray(ezarray);
	printf("erasing elements 1 tot 3\n");
	ezarray_erase(&ezarray, 1, 3);
	print_int_ezarray(ezarray);
	printf("%s\n", (ezstring = new_ezstring("This is a ezstring created using ezmem and returned using .tostring")).tostring);
	printf("Cleaning...\n");
	destroy_ezarray(&ezarray);
	destroy_ezstring(&ezstring);
	printf("Creating custom sized ezarray...\n");
	ezarray = new_ezarray_dirty(other, 2000, sizeof(t_vec3));
	vector = ezarray_get_index(ezarray, 0);
	*(vector) = (t_vec3){1, 2, 3};
	printf("index 0 of 1999 : %p\nvalues %f, %f, %f\n", vector, vector->x, vector->y, vector->z);
	vector = ezarray_get_index(ezarray, 1);
	printf("index 1 of 1999 : %p\n", vector);
	ezarray_push(&ezarray, &vector);
	vector = ezarray_get_index(ezarray, 2000);
	printf("index 2000 of 1999 : %p\n", vector);
	printf("Cleaning again...\n");
	destroy_ezarray(&ezarray);
	printf("Creating ezarray of type 'other' with no specified size... Kidding, DON'T DO THAT !\n");
	printf("Creating new ezlink...\n");
	ezlink = new_ezlink(unsigned_int, 10);
	ezlink_append(ezlink, new_ezlink(unsigned_char, 100));
	printf("Next link adress %p\nDestroying new link...\n", ezlink->next);
	destroy_ezlink(ezlink->next);
	printf("New next link adress %p (expecting NULL)\n", ezlink->next);
	ezlink_append(ezlink, new_ezlink(unsigned_char, 100));
	printf("New next link adress %p\n", ezlink->next);
	destroy_ezchain(ezlink);
	printf("Performance test with reserve, pushing 50.000.000 values to unsigned int array...\n");
	printf("Time elapsed : %li milliseconds.\n", performance_test_reserve(50000000));
	printf("Performance test without reserve, pushing 50.000.000 values to unsigned int array...\n");
	printf("Time elapsed : %li milliseconds.\n", performance_test_woreserve(50000000));
	return (0);
}