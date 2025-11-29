# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 16:08:52 by khanadat          #+#    #+#              #
#    Updated: 2025/11/29 19:33:14 by khanadat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------------------------------------------------------------------- #
#                                   VARIABLES                                   #
# ----------------------------------------------------------------------------- #

# --- EXECUTABLE NAMES ---
NAME            = miniRT

# --- COMPILER & FLAGS ---
CC              = cc
CFLAGS          = -Wall -Wextra -Werror $(addprefix -I,$(INCDIRS))
AR              = ar
ARFLAGS         = rcs

MLXFLAGS	= -I $(MLX_DIR)
LIBFTFLAGS	= -I $(LIBFTDIR)
CFLAGS		+= $(MLXFLAGS)
CFLAGS		+= $(LIBFTFLAGS)

# --- COMMANDS ---
RMDIR           = rm -rf

# --- DIRECTORIES ---

INCDIRS          =	include\
					$(LIBFTDIR)/include \
					$(MLXDIR)/include

SRCDIR_BASE     = ./src
SRCDIR          = $(SRCDIR_BASE)

OBJDIR_BASE     = ./obj
OBJDIR          = $(OBJDIR_BASE)

LIBFTDIR        = ./libft
MLXDIR			= ./minilibx_linux

# --- LIBRARIES ---
LIBFT			= $(LIBFTDIR)/libft.a
MLX				= $(MLXDIR)/libmlx.a


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


# --- FILES ---

SRC_FILES       =	main.c \
					utils0.c \
					utils_set.c \
					validate.c \
					validate_utils0.c \
					validate_ambient.c \

SRCS            = $(foreach file,$(SRC_FILES),$(shell find $(SRCDIR) -name $(file)))

# --- OBJECTS ---
OBJS            = $(patsubst $(SRCDIR_BASE)/%.c, $(OBJDIR_BASE)/%.o, $(SRCS))

# --- DEBUGGING ---
VALGRIND        = valgrind
VALGRIND_FLAGS  = --leak-check=full --track-origins=yes --show-leak-kinds=all
DFLAGS          = -g -O0
ASAN_FLAGS      = -g -fsanitize=address
SCAN_BUILD      = scan-build

# ----------------------------------------------------------------------------- #
#                                     RULES                                     #
# ----------------------------------------------------------------------------- #

# --- MAIN TARGETS ---
all:            $(NAME)

# --- EXECUTABLE BUILDING ---
$(NAME):        $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft
	@echo "\n\033[1;32m'$(NAME)' has been created!\033[0m"

# --- LIBRARY BUILDING ---
$(LIBFT):
	@make -sC $(LIBFTDIR)

# needed mlx

# --- OBJECT FILE COMPILATION ---
$(OBJDIR_BASE)/%.o: $(SRCDIR_BASE)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# --- CLEANUP RULES ---
clean:
	@$(RMDIR) $(OBJDIR_BASE)
	@make clean -C $(LIBFTDIR)
	@echo "\033[1;33mObject files cleaned.\033[0m"

fclean:         clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFTDIR)
	@echo "\033[1;31mAll cleaned.\033[0m"

re:             fclean all

# --- DEBUGGING & TESTING ---
lldb: fclean
	@$(MAKE) CFLAGS="$(CFLAGS) $(DFLAGS)" $(NAME)
	@echo "\n\033[1;35mLaunching LLDB for '$(NAME)'...\033[0m"
	@lldb $(NAME)

asan: fclean
	@$(MAKE) CFLAGS="$(CFLAGS) $(ASAN_FLAGS)" LDFLAGS="$(ASAN_FLAGS)" $(NAME)
	@echo "\n\033[1;35mCompiled with AddressSanitizer. Run './$(NAME)' to test.\033[0m"

valgrind: fclean
	@$(MAKE) CFLAGS="$(CFLAGS) $(DFLAGS)" $(NAME)
	@echo "\n\033[1;36mRunning Valgrind for '$(NAME)'...\033[0m"
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME)

test: all
	@$(MAKE) all
	@echo "\033[1;36mRunning tests with Valgrind...\033[0m"
	@$(CC) $(CFLAGS) test.c $(NAME) -o test_runner
	$(VALGRIND) $(VALGRIND_FLAGS) ./test_runner
	@$(RM) test_runner

scanb: fclean
	@$(SCAN_BUILD) $(MAKE) all

# --- PHONY TARGETS ---
.PHONY:         all clean fclean re test debug asan valgrind
