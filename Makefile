# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akihito <akihito@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 21:27:07 by akihito           #+#    #+#              #
#    Updated: 2022/01/15 17:08:03 by akihito          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "pushswap"

SRC = push_swap.c\
		operation/command_a.c\
		operation/commnad_b.c\
		operation/command_both.c
CC = gcc

HEADER = includes/push_swap.h

LIBS = -L./libft -lft

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.0)

MAKE = $(make)
all : $(LIBFT) $(NAME)

$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean :
	rm -f $(NAME)
	rm -f ($(LIBFT_DIR))

re : fclean all

.PHONY: all clean fclean re