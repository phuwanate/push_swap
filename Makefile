# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 10:44:04 by plertsir          #+#    #+#              #
#    Updated: 2023/06/06 16:49:55 by plertsir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc -fsanitize=address -g
FLAGS = -Wall -Werror -Wextra
LIBARIES =  -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_DIRECTORY)

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADER_DIRECTORY), $(HEADER_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = push_swap.c get_stack.c free_mem.c get_index.c\
			   radix_sort.c move_a.c  move_b.c update_stack.c\
			   sort_three.c sort_five.c utils.c utils_2.c utils_3.c

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
		$(CC) $(FLAGS) $(LIBARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIRECTORY):
		mkdir -p $(OBJECTS_DIRECTORY)
	
$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
		$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
		$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
		$(MAKE) -sC $(LIBFT_DIRECTORY) clean
		rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
		rm -rf $(LIBFT)
		rm -rf $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all
