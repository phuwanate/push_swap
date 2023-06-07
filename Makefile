# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 10:44:04 by plertsir          #+#    #+#              #
#    Updated: 2023/06/07 11:26:41 by plertsir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
#CC = gcc -fsanitize=address -g
CC = gcc -g
FLAGS = -Wall -Werror -Wextra
LIBARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_DIRECTORY)

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY_A = ./sources/main/
SOURCES_LIST_A = push_swap.c get_stack.c free_mem.c get_index.c update_stack.c

SOURCES_DIRECTORY_B = ./sources/move/
SOURCES_LIST_B = move_a.c move_b.c

SOURCES_DIRECTORY_C = ./sources/sort/
SOURCES_LIST_C = radix_sort.c sort_five.c sort_three.c

SOURCES_DIRECTORY_D = ./sources/utils/
SOURCES_LIST_D = utils.c utils_2.c utils_3.c

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST_A = $(patsubst %.c, %.o, $(SOURCES_LIST_A))
OBJECTS_LIST_B = $(patsubst %.c, %.o, $(SOURCES_LIST_B))
OBJECTS_LIST_C = $(patsubst %.c, %.o, $(SOURCES_LIST_C))
OBJECTS_LIST_D = $(patsubst %.c, %.o, $(SOURCES_LIST_D))
OBJECTS_A = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_A))
OBJECTS_B = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_B))
OBJECTS_C = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_C))
OBJECTS_D = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_D))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS_A) $(OBJECTS_B) $(OBJECTS_C) $(OBJECTS_D)
	$(CC) $(FLAGS) $(LIBARIES) $(INCLUDES) $(OBJECTS_A) $(OBJECTS_B) $(OBJECTS_C) $(OBJECTS_D) -o $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY_A)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY_B)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY_C)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY_D)%.c $(HEADERS)
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

