# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 16:08:52 by khanadat          #+#    #+#              #
#    Updated: 2025/11/14 11:57:31 by khanadat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= miniRT
CC			:= cc
CCFLAGS		:= -Wall -Wextra -Werror# -lm

SRCS		:= main.c
RM			:= rm -rf

OBJS_DIR	:= objs
OBJS		:= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR	:= libft
LIBFT_A		:= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	:= -I $(LIBFT_DIR)/includes

MLX_DIR		:= minilibx-linux
MLX_A		:= $(MLX_DIR)/libmlx.a

MLX_FLAGS	:= -I $(MLX_DIR) #-lx11 -lXext

LD_FLAGS	:= -L $(MLX_DIR) -L $(LIBFT_DIR)

.PHONY	:	all clean fclean re

all		: $(NAME)
$(NAME)	: $(OBJS) $(LIBFT_A) $(MLX_A)
	$(CC) $(CCFLAGS) $(LD_FLAGS) $^ -o $@

$(LIBFT_DIR):
	git clone git@github.com:dattekoda/libft.git $@
	$(RM) $@/.git

$(LIBFT_A): $(LIBFT_DIR)
	make bonus -C $^

$(MLX_A):
	make -C $(MLX_DIR)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@);
	$(CC) $(CCFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJS_DIR)
	make clean -C $(MLX_DIR)
	make fclean -C $(LIBFT_DIR)

fclean	: clean
	rm -rf $(NAME)

re: clean all