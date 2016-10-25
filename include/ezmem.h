/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ezmem.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 00:16:20 by gpinchon          #+#    #+#             */
/*   Updated: 2016/10/25 22:11:05 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EZMEM_H
# define EZMEM_H

# include <stdlib.h>

# define UCHAR 		unsigned char
# define UINT		unsigned int
# define TYPE		e_type
# define ARRAY		t_array
# define STRING		t_string
# define BOOL		e_bool
# define SIGNED		0x000
# define UNSIGNED	0x100
# define SHORT		0x010
# define LONG		0x020
# define CHAR		0x000
# define INT		0x001
# define FLOAT		0x002
# define DOUBLE		0x003
# define OTHER		0x004
//#define ENUM		0x006


typedef enum {
	signed_char = SIGNED | CHAR,
	unsigned_char = UNSIGNED | CHAR,
	signed_short = SIGNED | SHORT | INT,
	unsigned_short = UNSIGNED | SHORT | INT,
	signed_long = SIGNED | LONG | INT,
	unsigned_long = UNSIGNED | LONG | INT,
	signed_int = SIGNED | INT,
	unsigned_int = UNSIGNED | INT,
	signed_float = FLOAT,
	signed_double = DOUBLE,
	long_double = LONG | DOUBLE,
	other = OTHER
} e_type;

typedef enum {
	false = 0,
	true = !false
} e_bool;

typedef struct	s_array
{
	TYPE		type;
	UINT		data_size;
	UINT		length;
	UINT		total_size;
	void		*data;
}				t_array;

typedef struct	s_string
{
	UINT		length;
	char		*tostring;
	t_array		array;
}				t_string;

t_array		new_array(const TYPE datatype, UINT length, ...);
t_array		new_array_dirty(const TYPE datatype, UINT length, ...);
t_string	new_string(const char *src);
void		realloc_array(ARRAY *array, UINT new_length);
void		*get_array_index(const ARRAY array, const UINT index);
BOOL		array_is_signed(const ARRAY array);
void		destroy_array(ARRAY *array);
void		destroy_string(STRING *str);

#endif