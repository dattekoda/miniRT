# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 20:41:19 by ikawamuk          #+#    #+#              #
#    Updated: 2026/01/28 16:23:09 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT

CC			=	cc
CFLAG		=	-Wall -Wextra -Werror $(patsubst %,-I%,$(INCDIRS)) -I$(MLXDIR) \
				-I$(LIBFTDIR)/include -O3 -march=native
RMDIR		=	rm -rf

# --- src ---
SRCDIR		=	src

SRCS	=	$(addprefix $(SRCDIR)/, \
				main.c \
				mini_rt.c \
				get_camera_ray.c \
				$(addprefix init_world/, \
					init_world.c \
					set_option.c \
					read_rt_file.c \
					$(addprefix define/, \
					define_element.c \
					define_option.c \
					define_skips.c \
					) \
					$(addprefix validate_arguments/, \
					validate_arguments.c \
					is_valid_file_name.c \
					is_valid_option.c \
					) \
					$(addprefix is_valid_line_list/, \
						is_valid_element.c \
						is_valid_line.c \
						is_valid_line_list.c \
						$(addprefix skips/, \
							skip_until_end.c \
							skip_value.c \
							skip_vector.c \
						) \
						$(addprefix utils/, \
							err_point_out.c \
							skip_material.c \
							skip_range.c \
							skip_spaces.c \
							skip_texture.c \
							skip_vec.c \
						) \
					) \
					$(addprefix create_world/, \
						create_world.c \
						set_ambient.c \
						$(addprefix set_camera/, \
							construct_camera.c \
							set_camera.c \
						) \
						$(addprefix set_light/, \
							set_light.c \
							preprocess_line_list.c \
						) \
						$(addprefix texture/, \
							generate_solid_texture.c \
						) \
						$(addprefix material/, \
							generate_lambertian.c \
							generate_light.c \
							$(addprefix pdf/, \
								calc_light_pdf_value.c \
								cosine_pdf.c \
								light_pdf.c \
								mixture_pdf.c \
								random_light_pdf.c \
							) \
						) \
						$(addprefix hitter/, \
							generate_cylinder.c \
							generate_disk.c \
							generate_sphere.c \
							solution.c \
							$(addprefix aabb/, \
								aabb.c \
							) \
							$(addprefix hit/, \
								hit_disk.c \
								hit_sphere.c \
							) \
							$(addprefix line_to_hitter/, \
								line_to_cylinder.c \
								line_to_disk.c \
								line_to_light.c \
								line_to_material.c \
								line_to_plane.c \
								line_to_sphere.c \
							) \
						) \
						$(addprefix set_objects/, \
							line_list_to_bvh.c \
							set_objects.c \
							$(addprefix hitter_arr_to_bvh/, \
								bvh_utils.c \
								find_best_split_info.c \
								generate_tree.c \
								hit_arr_to_bvh.c \
								sort_hit_arr.c \
							) \
							$(addprefix line_list_to_hitter_arr/, \
								add_cylinder_disk.c \
								line_list_to_hit_arr.c \
							) \
						) \
					) \
					$(addprefix utils/, \
						char_to_idx.c \
						match_identifer.c \
						token_to_str.c \
						token_to_value.c \
						token_to_vec.c \
					) \
				) \
				$(addprefix ray/, \
					ray.c \
				) \
				$(addprefix utils/, \
					construct_result.c \
					utils_clear.c \
					utils_err.c \
					utils_float.c \
					utils_random.c \
					utils_swap.c \
					$(addprefix vec/, \
						onb.c \
						range.c \
						vec2.c \
						vec3.c \
						vec3_basic.c \
						vec3_product.c \
						vec3_scal.c \
					) \
				) \
			)


# --- obj ---
OBJDIR		=	obj
OBJS		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# --- include ---
INCDIRS		=	$(shell find include -type d)

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
TESTCFLAG	=	$(ASANFLAG) -Itest/utils
TESTLDFLAG	=	$(LDFLAG) -Wl,--wrap=open,--wrap=read,--wrap=malloc,--wrap=free,--wrap=exit

TESTSRCFILES	=	$(addprefix test/, \
						test.c \
						test_mini_rt.c \
						$(addprefix init_world/, \
							test_init_world.c \
							test_set_option.c \
							test_read_rt_file.c \
							$(addprefix test_validate_arguments/, \
								test_validate_arguments.c \
								test_is_valid_file_name.c \
								test_is_valid_option.c \
							) \
							$(addprefix test_is_valid_line_list/, \
								test_is_valid_line_list.c \
								test_line_to_value.c \
								test_skip_color.c \
								test_skip_point.c \
								test_skip_range.c \
								test_skip_spaces.c \
								test_skip_unit.c \
								test_skip_until_end.c \
							) \
							$(addprefix test_create_world/, \
								test_create_world.c \
								test_set_ambient.c \
								test_set_camera.c \
								$(addprefix test_set_light/, \
									test_set_light.c \
									test_add_light_radius.c \
									test_line_to_light.c \
								) \
								$(addprefix test_set_objects/, \
									test_set_objects.c \
									$(addprefix test_line_list_to_bvh/, \
									test_line_list_to_bvh.c \
										$(addprefix test_line_list_to_hit_arr/, \
										test_line_list_to_hit_arr.c \
										) \
										$(addprefix test_hit_arr_to_bvh/, \
										test_hit_arr_to_bvh.c \
										) \
									) \
								) \
							) \
							$(addprefix test_utils/, \
								test_match_identifer.c \
							) \
						) \
						$(addprefix utils/, \
							syscall_mock.c \
							vec_equal.c \
							print_vec.c \
						) \
					)

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
test:
	@$(MAKE) $(TESTNAME)
	@echo "\033[1;36mRunning tests ...\033[0m"
	./$(TESTNAME)

$(TESTNAME):$(TESTOBJS) $(MLX) $(LIBFT)
	$(CC) $(TESTOBJS) $(TESTCFLAG) $(TESTLDFLAG) $(LDLIBS) -o $@

# --- scan build ---$(INCDIRS)/test/
scanb: fclean
	@$(SCANBUILD) $(MAKE) all

.PHONY:	all clean fclean re test debug asan valgrind scanb