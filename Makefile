# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/03 16:01:39 by khanadat          #+#    #+#              #
#    Updated: 2026/01/05 23:01:45 by khanadat         ###   ########.fr        #
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
				mini_rt.c \
				init_world.c \
				util/util_err.c \
				validate/validate_file_name.c \
				validate/validate_arguments.c

SRCS		=	$(addprefix $(SRCDIR)/, $(SRCFILES))

# --- obj ---
OBJDIR		=	obj
OBJS		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# --- include ---
INCDIRS		=	include \
				include/util \
				include/validate

# --- OS DETECTION ---
UNAME	=	$(shell uname -s)
ifeq ($(UNAME),Darwin)
	MLXDIR := $(HOME)/minilibx
	MLXFLAG := -framework OpenGL -framework AppKit
	GITHUBURL := https://github.com/dannywillems/minilibx.git
else ifeq ($(UNAME),Linux)
	MLXDIR := minilibx-linux
	MLXFLAG := -lX11 -lXext
	GITHUBURL := https://github.com/42paris/minilibx-linux.git
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
DFLAG		=	$(CFLAG) -g -O0
ASANFLAG	=	$(DFLAG) -fsanitize=address
SCANBUILD	=	/usr/bin/scan-build-12

# --- test ---
TESTNAME	=	test_weekend_c
TESTCFLAG	=	$(ASANFLAG) -Itest/unit_test
TESTLDFLAG	=	$(LDFLAG) -Wl,--wrap=open,--wrap=read,--wrap=malloc,--wrap=free

TESTSRCFILES	=	$(addprefix test/, \
					test.c \
					$(addprefix unit_test/, \
					syscall_mock.c \
					$(addprefix set_world/, \
					test_set_option.c \
					$(addprefix validate/, \
					test_validate_file_name.c \
					))))

TESTSRCS		=	$(TESTSRCFILES) \
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
	@git clone $(GITHUBURL)
	@$(MAKE) -C $(MLXDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAG) -c $< -o $@

clean:
	@$(RMDIR) $(OBJDIR)
# @$(MAKE) -C $(LIBFTDIR) fclean
# @$(MAKE) -C $(MLXDIR) clean

fclean: clean
	$(RM) $(NAME) $(TESTNAME)

re: fclean all

# --- DEBUGGIN & TESTING ---
lldb: CFLAG=$(CFLAG) $(DFLAG)
lldb: fclean $(NAME)
	@echo "\n\033[1;35mLaunching LLDB for '$(NAME)'...\033[0m"
	@lldb $(NAME)

# --- address sanitizer ---
asan: CFLAG=$(CFLAG) $(ASANFLAG)
asan: LDFLAG=$(LDFLAG) $(ASANFLAG)
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

# --- scan build ---$(INCDIRS)/test/
scanb: fclean
	@$(SCANBUILD) $(MAKE) all

.PHONY:	all clean fclean re test debug asan valgrind scanb