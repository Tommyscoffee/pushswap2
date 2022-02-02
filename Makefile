# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 21:27:07 by akihito           #+#    #+#              #
#    Updated: 2022/02/02 14:50:12 by atomizaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "pushswap"

D_NAME = "pushswap_DBG"

ADDRESS_NAME = "pushswap_ADDRESS"

EXEC_DIR = exec

SRC = src/push_swap.c\
		src/utils.c\
		src/operation/command_a.c\
		src/operation/command_b.c\
		src/operation/command_both.c\
		src/operation/operation.c\
		src/operation/operation2.c\
		src/operation/operation3.c\
		src/quick_sort/Qsort.c\
		src/utils/util.c\
		src/utils/estimate.c\
		inits/init_func.c\
		src/quick_sort/Qsort_utils.c\
		src/quick_sort/bottom_utils.c\
		src/quick_sort/Qsort_utils_check.c\
		src/quick_sort/Sort_bottom.c\
		src/quick_sort/Sort_bottom_second.c\
		src/quick_sort/push_half.c\
		src/quick_sort/Sort_top_3.c\
		src/quick_sort/make_pivot.c\
		src/quick_sort/make_after_size.c\
		src/after_half/after_half.c\

DEBUG_SRC = debug/debug.c

CC = gcc

HEADER = includes/push_swap.h

LIBS = -L./libft -lft

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

OBJS := $(SRCS:.c=.o)

D_OBJS := $(DEBUG_SRCS:.c=.o)

DEBUG_OBJS := $(B_SRCS:.c=.o)

.c.o:
	$(CC) -c $< -I includes $(HEADER)

$(OBJS): $(SRC) $(LIBFT)
	$(CC) -c $(SRC)

$(D_OBJS): $(SRC) $(LIBFT)
	$(CC) -c $(DEBUG_SRC)

all : $(NAME)

$(NAME):$(SRC) $(LIBFT) $(DEBUG_SRC) $(EXEC_DIR)
	$(CC) $(SRC) $(DEBUG_SRC) $(LIBFT) -o $(NAME)

# debug: $(SRC) $(DEBUG_SRC) $(LIBFT) $(EXEC_DIR)key

ad: $(SRC) $(DEBUG_SRC) $(LIBFT) 
	$(CC) $(SRC) $(DEBUG_SRC) $(LIBFT) -fsanitize=address -o $(NAME)

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