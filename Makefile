# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/23 00:22:53 by gpinchon          #+#    #+#              #
#    Updated: 2017/02/13 18:43:48 by gpinchon         ###   ########.fr        #
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
			./src/ezmemalloc.c		\
			./src/get_data.c

#OBJ		= $(SRC:.c=.o)
OBJ 	= final.o
CC		= gcc
CFLAGS	= -Ofast -Wall -Wextra -Wall -I ./include

ifeq ($(OS), Windows_NT)
OK_STRING=[OK]
else
NO_COLOR=\033[0m
OK_COLOR=\033[32;01m
OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
endif

$(NAME): $(OBJ) 
	ar -rc $(NAME) $(OBJ)

%.o: %.hyper
	@echo -n Compiling $@...
	@($(CC) -x c $(CFLAGS) -o $@ -c $<)
	@echo "$(OK_STRING)"

.INTERMEDIATE: final.hyper
final.hyper: $(SRC)
	@echo -n Generating $@...
	@(cat $^ > final.hyper)
	@echo "$(OK_STRING)"

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(TEST)

re: fclean $(NAME)

test:
	gcc $(CFLAGS) $(TESTSRC) -L . -lezmem -o $(TEST)
