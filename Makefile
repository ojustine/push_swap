# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojustine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 13:27:35 by ojustine          #+#    #+#              #
#    Updated: 2020/08/13 03:07:18 by ojustine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
LIBFT_A = libft/libft.a
CHECKER = checker
PUSH_SWAP = push_swap

FLAGS = -Wall -Wextra -Werror -O2

LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj

HEADERS = -I./libft -I./inc

INCS_PUSH_SWAP = inc/push_swap.h

INCS_CHECKER = inc/checker.h

INCS_COMMON = inc/get_next_line.h
INCS_COMMON += inc/operation.h
INCS_COMMON += inc/parser.h
INCS_COMMON += inc/printer.h
INCS_COMMON += inc/properties.h
INCS_COMMON += inc/stack.h

SRCS_CHECKER = checker/checker.c
SRCS_PUSH_SWAP = push_swap/push_swap.c
SRCS_PUSH_SWAP += push_swap/inc_seq.c
SRCS_PUSH_SWAP += push_swap/move_set.c
SRCS_PUSH_SWAP += push_swap/sort_3.c
SRCS_PUSH_SWAP += push_swap/sort_do.c
SRCS_PUSH_SWAP += push_swap/sort_main.c
SRCS_PUSH_SWAP += push_swap/sort_prepare.c
SRCS_PUSH_SWAP += push_swap/util.c
SRCS_COMMON = common/config.c
SRCS_COMMON += common/operation.c
SRCS_COMMON += common/parser.c
SRCS_COMMON += common/printer.c
SRCS_COMMON += common/stack.c
SRCS_COMMON += common/properties/properties.c
SRCS_COMMON += common/properties/property.c
SRCS_COMMON += common/get_next_line.c

SRCS_CHECKER_PATH = $(addprefix $(SRC_DIR)/, $(SRCS_CHECKER))
SRCS_PUSH_SWAP_PATH = $(addprefix $(SRC_DIR)/, $(SRCS_PUSH_SWAP))
SRCS_COMMON_PATH = $(addprefix $(SRC_DIR)/, $(SRCS_COMMON))

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_COMMON = $(SRCS_COMMON:.c=.o)

OBJS_CHECKER_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS_CHECKER))
OBJS_PUSH_SWAP_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS_PUSH_SWAP))
OBJS_COMMON_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS_COMMON))

.PHONY: clean fclean all re make_lib

all : $(CHECKER) $(PUSH_SWAP)

$(LIBFT_A) : make_lib
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS_CHECKER_PATH))
	@mkdir -p $(dir $(OBJS_PUSH_SWAP_PATH))
	@mkdir -p $(dir $(OBJS_COMMON_PATH))

make_lib :
	$(MAKE) -C $(LIBFT_DIR)

$(CHECKER) : $(LIBFT_A) $(OBJS_CHECKER_PATH) $(OBJS_COMMON_PATH) $(INCS_CHECKER) $(INCS_COMMON)
	$(CC) -o $@ $(OBJS_CHECKER_PATH) $(OBJS_COMMON_PATH) $(LIBFT_A) $(HEADERS)

$(PUSH_SWAP) : $(LIBFT_A) $(OBJS_PUSH_SWAP_PATH) $(OBJS_COMMON_PATH) $(INCS_PUSH_SWAP) $(INCS_COMMON)
	$(CC) -o $@ $(OBJS_COMMON_PATH) $(OBJS_PUSH_SWAP_PATH) $(LIBFT_A) $(HEADERS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDES) Makefile
	$(CC) -o $@ -c $< $(HEADERS) $(FLAGS)

clean :
	$(RM) -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) -rf $(CHECKER) $(PUSH_SWAP)
	$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all
