# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/03 16:01:39 by khanadat          #+#    #+#              #
#    Updated: 2026/01/16 15:07:24 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT

CC			=	cc
CFLAG		=	-Wall -Wextra -Werror $(patsubst %,-I%,$(INCDIRS)) -I$(MLXDIR) \
				-I$(LIBFTDIR)/include -O3 -march=native
RMDIR		=	rm -rf

# --- src ---
SRCDIR		=	src

SRCS		=	$(addprefix $(SRCDIR)/, \
				main.c \
				mini_rt.c \
				$(addprefix utils/, \
				utils_float.c \
				utils_err.c \
				$(addprefix vec/, \
				onb.c \
				vec3_basic.c \
				vec3_product.c \
				vec3_scal.c \
				vec3.c\
				) \
				) \
				$(addprefix init_world/, \
				init_world.c \
				init_element.c \
				read_rt.c \
				set_option.c \
				$(addprefix create_world/, \
				create_world.c\
				set_ambient.c \
				set_camera.c \
				set_light.c \
				) \
				$(addprefix set_object/, \
				set_objects.c \
				set_objects_in_table.c \
				line_to_sphere.c \
				line_to_light.c \
				line_list_to_object_arr.c \
				gen_bvh.c \
				) \
				$(addprefix validate/, \
				construct_result.c \
				err_point_out.c \
				validate_line_list.c \
				validate_element.c \
				skip_spaces.c \
				skip_vec.c \
				token_to_value.c \
				token_to_vec.c \
				skip_range.c \
				value_skips.c \
				vector_skips.c \
				) \
				) \
				)

# --- obj ---
OBJDIR		=	obj
OBJS		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# --- include ---
INCDIRS		=	include \
				include/init_world \
				include/init_world/validate \
				include/utils \
				include/utils/vec \

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
TESTNAME	=	test_miniRT
TESTCFLAG	=	$(ASANFLAG) -Itest/unit_test
TESTLDFLAG	=	$(LDFLAG) -Wl,--wrap=open,--wrap=read,--wrap=malloc,--wrap=free

TESTSRCFILES	=	$(addprefix test/, \
					test.c \
					$(addprefix unit_test/, \
					syscall_mock.c \
					test_token_to_value.c \
					$(addprefix init_world/, \
					test_set_option.c \
					$(addprefix validate/, \
					test_skips.c \
					test_skip_color.c \
					test_skip_point.c \
					test_skip_range.c \
					test_skip_spaces.c \
					test_skip_unit.c \
					test_skip_until_end.c \
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