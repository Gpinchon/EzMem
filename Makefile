# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/23 00:22:53 by gpinchon          #+#    #+#              #
#    Updated: 2016/11/21 11:59:36 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libezmem.a
TEST	= ezmemtest
TESTSRC	= test.c
SRC		=	./src/new_arrays.c		\
			./src/new_link.c		\
			./src/append_link.c		\
			./src/foreach.c			\
			./src/manage_arrays.c	\
			./src/destroy_arrays.c	\
			./src/destroy_link.c	\
			./src/pushpop.c			\
			./src/shiftunshift.c	\
			./src/ezmemalloc.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Ofast -Wall -Wextra -Wall -I ./include

$(NAME): $(OBJ) 
	ar -rc $(NAME) $(OBJ)

NO_COLOR=\033[0m
OK_COLOR=\033[32;01m
OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
%.o: %.c
	@echo -n Compiling $@...
	@($(CC) $(CFLAGS) -o $@ -c $<)
	@echo "$(OK_STRING)"

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(TEST)

re: fclean $(NAME)

test:
	gcc $(CFLAGS) $(TESTSRC) -L . -lezmem -o $(TEST)
