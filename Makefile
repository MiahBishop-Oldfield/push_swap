# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 18:45:04 by mbishop-          #+#    #+#              #
#    Updated: 2022/06/08 18:45:42 by mbishop-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra
LIB = libft
SOURCES = loadargs.c \
		  recursionbubblesort.c \
		  groupsort.c\
		  sort_utils.c \
		  mainoperations.c \
		  stack_utils.c \
		  stackoperations.c \
		  check.c \
		  cleandata.c \
		  print.c 
HEADERS = push_swap.h

all: $(NAME) $(BONUS)

$(NAME): $(SOURCES)
	make -C $(LIB)
	$(CC) $(FLAGS) $(NAME).c $(SOURCES) -L$(LIB) -lft -o $(NAME)
	
$(BONUS): $(SOURCES)
	$(CC) $(FLAGS) $(BONUS).c $(SOURCES) -L$(LIB) -lft -o $(BONUS)

clean:
	make clean -C $(LIB)
	rm $(NAME) $(BONUS)

fclean:
	make fclean -C $(LIB)
	rm $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
