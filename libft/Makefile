# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 20:32:41 by khanadat          #+#    #+#              #
#    Updated: 2026/01/08 11:29:06 by khanadat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror

INCFLAGS = -Iinclude -Iinclude/ft_get_next_line -Iinclude/ft_strtod
AR = ar rcs
RM = rm -rf

SRC =	src/ft_strtod/ft_strtod.c \
		src/ft_strtod/strtod_set.c \
		src/ft_strtod/strtod_valid.c \
		src/ft_get_next_line/ft_get_next_line.c \
		src/ft_abs.c \
		src/ft_atoi.c \
		src/ft_atof.c \
		src/ft_bzero.c \
		src/ft_calloc.c \
		src/ft_isalnum.c \
		src/ft_isalpha.c \
		src/ft_isascii.c \
		src/ft_isdigit.c \
		src/ft_isprint.c \
		src/ft_isspace.c \
		src/ft_itoa.c \
		src/ft_max.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_memcpy.c \
		src/ft_memmove.c \
		src/ft_memset.c \
		src/ft_min.c \
		src/ft_putchar_fd.c \
		src/ft_putendl_fd.c \
		src/ft_putnbr_fd.c \
		src/ft_putstr_fd.c \
		src/ft_split.c \
		src/ft_strchr.c \
		src/ft_strcmp.c \
		src/ft_strdup.c \
		src/ft_striteri.c \
		src/ft_strjoin.c \
		src/ft_strlcat.c \
		src/ft_strlcpy.c \
		src/ft_strlen.c \
		src/ft_strmapi.c \
		src/ft_strncmp.c \
		src/ft_strndup.c \
		src/ft_strnstr.c \
		src/ft_strrchr.c \
		src/ft_strtrim.c \
		src/ft_substr.c \
		src/ft_tolower.c \
		src/ft_toupper.c

BONUS =	bonus/ft_lstnew_bonus.c \
		bonus/ft_lstadd_front_bonus.c \
		bonus/ft_lstsize_bonus.c \
		bonus/ft_lstlast_bonus.c \
		bonus/ft_lstadd_back_bonus.c \
		bonus/ft_lstdelone_bonus.c \
		bonus/ft_lstclear_bonus.c \
		bonus/ft_lstiter_bonus.c \
		bonus/ft_lstmap_bonus.c

OBJ_DIR		= objs
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BONUS	= $(addprefix $(OBJ_DIR)/, $(BONUS:.c=.o))

BUILD_OBJ	:= $(OBJ)

ifeq ($(MAKECMDGOALS),bonus)
	BUILD_OBJ += $(OBJ_BONUS)
else ifeq ($(MAKECMDGOALS),rebonus)
	BUILD_OBJ += $(OBJ_BONUS)
endif

.PHONY: all clean fclean re bonus rebonus

all: $(NAME)

$(NAME): $(BUILD_OBJ)
	$(AR) $@ $^

bonus: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus