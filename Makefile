# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 10:44:04 by plertsir          #+#    #+#              #
#    Updated: 2023/05/18 14:39:12 by plertsir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBARIES =  -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_DIRECTORY)

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADER_DIRECTORY), $(HEADER_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = push_swap.c push.c utils.c free_mem.c

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
		rm -tf $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all
