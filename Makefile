# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/03 16:01:39 by khanadat          #+#    #+#              #
#    Updated: 2026/01/03 19:01:39 by khanadat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT

CC			=	cc
CFLAG		=	-Wall -Wextra -Werror $(patsubst %,-I%,$(INCDIRS)) -I$(MLXDIR) \
				-I$(LIBFTDIR)/include -O3 -march=native
RMDIR		=	rm -rf

# --- src ---
SRCDIR		=	src
SRCFILES	=	main.c \
				mini_rt.c 

SRCS		=	$(addprefix $(SRCDIR)/, $(SRCFILES))

# --- obj ---
OBJDIR		=	obj
OBJS		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# --- include ---
INCDIRS		=	include

# --- OS DETECTION ---
UNAME	=	$(shell uname -s)
ifeq ($(UNAME),Darwin)
	MLXDIR := $(HOME)/minilibx
	MLXFLAG := -framework OpenGL -framework AppKit
else ifeq ($(UNAME),Linux)
	MLXDIR := minilibx-linux
	MLXFLAG := -lX11 -lXext
else
	$(error Unsupported OS: $(UNAME))
endif

# --- library ---
LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a
MLX			=	$(MLXDIR)/libmlx.a
LDFLAG		=	-L$(MLXDIR) -L$(LIBFTDIR)
LDLIBS		=	-lm -lmlx -lft $(MLXFLAG)

# --- DEBUGGING ---
VALGRIND	=	valgrind --leak-check=full --track-origins=yes \
				--show-leak-kinds=all
DFLAG		=	-g -O0
ASAN_FLAG	=	$(DFLAG) -fsanitize=address
SCAN_BUILD	=	/usr/bin/scan-build-12

# --- test ---
TESTNAME	=	test_weekend_c
TESTCFLAG	=	$(ASANFLAG) -I$(INCDIRS)/test/
TESTLDFLAG	=	$(LDFLAG) -Wl,--wrap=open,--wrap=read,--wrap=malloc, \
				--wrap=free
TESTSRCFILES	=	$(addprefix test/, test.c)
TESTSRCS		=	$(addprefix $(SRCDIR)/, $(TESTSRCFILES)) \
					$(filter-out $(SRCDIR)/main.c, $(SRCS))
TESTOBJS		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(TESTSRCS))

# --- Rules ---
all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAG) $(OBJS) $(LDFLAG) $(LDLIBS) -o $@
	@echo "\n\033[1;32m'$(NAME)' has been created!\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) bonus

$(MLX):
	@$(MAKE) -C $(MLXDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAG) -c $< -o $@

clean:
	@$(RMDIR) $(OBJDIR)
# @$(MAKE) -C $(LIBFTDIR) fclean
# @$(MAKE) -C $(MLXDIR) clean

re: fclean all

# --- DEBUGGIN & TESTING ---
lldb: CFLAG=$(CFLAG) $(DFLAG)
lldb: fclean $(NAME)
	@echo "\n\033[1;35mLaunching LLDB for '$(NAME)'...\033[0m"
	@lldb $(NAME)

# --- address sanitizer ---
asan: CFLAG=$(CFLAG) $(ASAN_FLAG)
asan: LDFLAG=$(LDFLAG) $(ASAN_FLAG)
asan: fclean $(NAME)
	@echo "\n\033[1;35mCompiled with AddressSanitizer. Run './$(NAME)' to test.\033[0m"

# --- valgrind ---
valgrind: CFLAG="$(CFLAG) $(DFLAG)"
valgrind: fclean $(NAME)
	@echo "\n\033[1;36mRunning Valgrind for '$(NAME)'...\033[0m"
	$(VALGRIND) $(VALGRIND_FLAG) ./$(NAME)

# --- debug ---
debug: CFLAG=$(DFLAG)
debug: re

# --- test ---
test: CFLAG=$(TESTFLAG)
test: LDFLAG=$(TESTLDFLAG)
test: fclean
	@$(MAKE) $(TESTNAME)
	@echo "\033[1;36mRunning tests ...\033[0m"
	./$(TESTNAME)

$(TESTNAME):$(TESTOBJS) $(MLX) $(LIBFT)
	$(CC) $(TESTOBJS) $(TESTCFLAG) $(TESTLDFLAG) $(LDLIBS) -o $@

# --- scan build ---
scanb: fclean
	@$(SCAN_BUILD) $(MAKE) all

.PHONY:	all clean fclean re test debug asan valgrind scanb