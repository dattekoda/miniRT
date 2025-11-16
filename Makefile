# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 16:08:52 by khanadat          #+#    #+#              #
#    Updated: 2025/11/16 13:18:31 by khanadat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= miniRT
CC			:= cc
CCFLAGS		:= -Wall -Wextra -Werror

SRCS		:= main.c utils0.c utils_set.c utils_validate.c
RM			:= rm -rf

OBJS_DIR	:= objs
OBJS		:= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR	:= libft
LIBFT_A		:= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	:= -I $(LIBFT_DIR)/includes


UNAME		:= $(shell uname -s)

ifeq ($(UNAME),Darwin)
	MLX_DIR		:= ~/minilibx_macos
	MLX_FLAGS	:= -framework OpenGL -framework AppKit
	CCFLAGS		:= -I mac_keypress
else ifeq ($(UNAME),Linux)
	MLX_DIR		:= minilibx_linux
	MLX_FLAGS	:= -lX11 -lXext
	CCFLAGS		:= -I linux_keypress
else
	$(error Unsupported OS: $(UNAME))
endif

MLX_A		:= $(MLX_DIR)/libmlx.a
MLX_FLAGS	+= -I $(MLX_DIR)
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

$(MLX_A): $(MLX_DIR)
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