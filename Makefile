# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 20:41:19 by ikawamuk          #+#    #+#              #
#    Updated: 2026/03/15 21:34:03 by khanadat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT

CC			=	cc
CFLAG		=	-Wall -Wextra -Werror $(patsubst %,-I%,$(INCDIRS)) -I$(MLXDIR) \
				-I$(LIBFTDIR)/include -O3 -march=native -MMD -MP
RMDIR		=	rm -rf

# --- src ---
SRCDIR		=	src

SRCS	=	$(addprefix $(SRCDIR)/, \
				main.c \
				mini_rt.c \
				$(addprefix define/, \
					define_window.c \
				) \
				$(addprefix init_world/, \
					init_world.c \
					set_option.c \
					read_rt_file.c \
					$(addprefix define/, \
					define_element.c \
					define_material.c \
					define_option.c \
					define_skips.c \
					define_texture.c \
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
						set_ambient_light.c \
						$(addprefix set_camera/, \
							construct_camera.c \
							set_camera.c \
						) \
						$(addprefix set_light/, \
							$(addprefix utils/, \
								add_light_radius.c \
								str_space_join.c \
							) \
							set_light.c \
							preprocess_line_list.c \
						) \
						$(addprefix texture/, \
							$(addprefix texture_utils/, \
								clone_texture.c \
							) \
							$(addprefix local_normal/, \
								define_local_normal.c \
								local_normal.c \
							) \
							generate_bump_texture.c \
							generate_checker_texture.c \
							generate_solid_texture.c \
						) \
						$(addprefix material/, \
							generate_dielectric.c \
							generate_lambertian.c \
							generate_metal.c \
							generate_light.c \
							$(addprefix material_utils/, \
								orient_normal.c \
								clone_material.c \
								refract.c \
							) \
							$(addprefix pdf/, \
								$(addprefix light_pdf_utils/, \
									calc_light_pdf_value.c \
									generate_light_pdf_direction.c \
								) \
								cosine_pdf.c \
								light_pdf.c \
								mixture_pdf.c \
							) \
						) \
						$(addprefix hitter/, \
							$(addprefix generate/, \
								generate_cone.c \
								generate_cylinder.c \
								generate_disk.c \
								generate_sphere.c \
								generate_plane.c \
								generate_triangle.c \
							) \
							$(addprefix aabb/, \
								aabb.c \
							) \
							$(addprefix hit/, \
								$(addprefix cylinder_utils/, \
									calc_cylinder_coeff.c \
									construct_cylinder_uv.c \
								) \
								$(addprefix triangle_utils/, \
									is_valid_tr_solution.c \
								) \
								$(addprefix plane_utils/, \
									construct_plane_uv.c \
									init_plane_solution.c \
								) \
								hit_cone.c \
								hit_disk.c \
								hit_sphere.c \
								hit_plane.c \
								hit_triangle.c \
								hit_cylinder.c \
							) \
							$(addprefix line_to_hitter/, \
								line_to_cone.c \
								line_to_cylinder.c \
								line_to_disk.c \
								line_to_light.c \
								line_to_material.c \
								line_to_plane.c \
								line_to_sphere.c \
								line_to_triangle.c \
							) \
							$(addprefix utils/, \
								solution.c \
								calc_normal_max.c \
							) \
						) \
						$(addprefix set_objects/, \
							line_list_to_bvh.c \
							set_objects.c \
							$(addprefix hitter_arr_to_bvh/, \
								bvh_utils.c \
								compare.c \
								construct_hitter_arr.c \
								find_best_split_info.c \
								prepare_surface_arr.c \
								generate_hitter_list.c \
								generate_tree.c \
								hit_arr_to_bvh.c \
								split.c \
							) \
							$(addprefix line_list_to_hitter_arr/, \
								add_cylinder_disk.c \
								add_hitter_list.c \
								line_list_to_hit_arr.c \
								line_list_to_hitter_list.c \
							) \
						) \
					) \
					$(addprefix utils/, \
						has_object_in_line_list.c \
						str_to_idx.c \
						match_identifer.c \
						search_object.c \
						token_to_str.c \
						token_to_value.c \
						token_to_vec.c \
					) \
				) \
				$(addprefix render_world/, \
					render_world.c \
					$(addprefix render_pixels/, \
						$(addprefix compute_phong_color/, \
							calc_color_from_light_list.c \
							compute_phong_color.c \
						) \
						calc_sample_pixel_color.c \
						compute_path_tracing_color.c \
						render_pixels.c \
					) \
					$(addprefix draw_image/, \
						$(addprefix utils/, \
							$(addprefix draw_mlx_image/, \
								mlx_utils.c \
								draw_mlx_image.c \
							) \
							draw_ppm_image.c \
						) \
						draw_image.c \
					) \
				) \
				$(addprefix ray/, \
					ray.c \
				) \
				$(addprefix utils/, \
					clock.c \
					construct_result.c \
					ft_qsort.c \
					ft_swap.c \
					utils_clamp.c \
					utils_clear.c \
					utils_err.c \
					utils_float.c \
					utils_random.c \
					$(addprefix vec/, \
						onb.c \
						range.c \
						vec2.c \
						vec3.c \
						vec3_basic.c \
						vec3_product.c \
						vec3_scal.c \
						reflect.c \
					) \
				) \
			)

# you can delete later
SRCS	+=	$(addprefix $(SRCDIR)/, \
				$(addprefix debug/, \
					print_aabb.c \
					print_axis.c \
					print_hitter_arr.c \
					print_hitter.c \
					print_line_list.c \
					print_material.c \
					print_ray.c \
					print_split.c \
					print_vec.c \
					print_world.c \
					print_option.c \
				) \
			)

SRCDIR_BONUS	=	src_bonus

SRCS_BONUS	=	$(addprefix $(SRCDIR_BONUS)/, \
					main_bonus.c \
					mini_rt_bonus.c \
					$(addprefix define/, \
						define_window_bonus.c \
					) \
					$(addprefix init_world/, \
						init_world_bonus.c \
						set_option_bonus.c \
						read_rt_file_bonus.c \
						$(addprefix define/, \
						define_element_bonus.c \
						define_material_bonus.c \
						define_option_bonus.c \
						define_skips_bonus.c \
						define_texture_bonus.c \
						) \
						$(addprefix validate_arguments/, \
						validate_arguments_bonus.c \
						is_valid_file_name_bonus.c \
						is_valid_option_bonus.c \
						) \
						$(addprefix is_valid_line_list/, \
							is_valid_element_bonus.c \
							is_valid_line_bonus.c \
							is_valid_line_list_bonus.c \
							$(addprefix skips/, \
								skip_until_end_bonus.c \
								skip_value_bonus.c \
								skip_vector_bonus.c \
							) \
							$(addprefix utils/, \
								err_point_out_bonus.c \
								skip_material_bonus.c \
								skip_range_bonus.c \
								skip_spaces_bonus.c \
								skip_texture_bonus.c \
								skip_vec_bonus.c \
							) \
						) \
						$(addprefix create_world/, \
							create_world_bonus.c \
							set_ambient_light_bonus.c \
							$(addprefix set_camera/, \
								construct_camera_bonus.c \
								set_camera_bonus.c \
							) \
							$(addprefix set_light/, \
								$(addprefix utils/, \
									add_light_radius_bonus.c \
									str_space_join_bonus.c \
								) \
								set_light_bonus.c \
								preprocess_line_list_bonus.c \
							) \
							$(addprefix texture/, \
								$(addprefix texture_utils/, \
									clone_texture_bonus.c \
								) \
								$(addprefix local_normal/, \
									define_local_normal_bonus.c \
									local_normal_bonus.c \
								) \
								generate_bump_texture_bonus.c \
								generate_checker_texture_bonus.c \
								generate_solid_texture_bonus.c \
							) \
							$(addprefix material/, \
								generate_dielectric_bonus.c \
								generate_lambertian_bonus.c \
								generate_metal_bonus.c \
								generate_light_bonus.c \
								$(addprefix material_utils/, \
									orient_normal_bonus.c \
									clone_material_bonus.c \
									refract_bonus.c \
								) \
								$(addprefix pdf/, \
									$(addprefix light_pdf_utils/, \
										calc_light_pdf_value_bonus.c \
										generate_light_pdf_direction_bonus.c \
									) \
									cosine_pdf_bonus.c \
									light_pdf_bonus.c \
									mixture_pdf_bonus.c \
								) \
							) \
							$(addprefix hitter/, \
								$(addprefix generate/, \
									generate_cone_bonus.c \
									generate_cylinder_bonus.c \
									generate_disk_bonus.c \
									generate_sphere_bonus.c \
									generate_plane_bonus.c \
									generate_triangle_bonus.c \
								) \
								$(addprefix aabb/, \
									aabb_bonus.c \
								) \
								$(addprefix hit/, \
									$(addprefix cylinder_utils/, \
										calc_cylinder_coeff_bonus.c \
										construct_cylinder_uv_bonus.c \
									) \
									$(addprefix triangle_utils/, \
										is_valid_tr_solution_bonus.c \
									) \
									$(addprefix plane_utils/, \
										construct_plane_uv_bonus.c \
										init_plane_solution_bonus.c \
									) \
									hit_cone_bonus.c \
									hit_disk_bonus.c \
									hit_sphere_bonus.c \
									hit_plane_bonus.c \
									hit_triangle_bonus.c \
									hit_cylinder_bonus.c \
								) \
								$(addprefix line_to_hitter/, \
									line_to_cone_bonus.c \
									line_to_cylinder_bonus.c \
									line_to_disk_bonus.c \
									line_to_light_bonus.c \
									line_to_material_bonus.c \
									line_to_plane_bonus.c \
									line_to_sphere_bonus.c \
									line_to_triangle_bonus.c \
								) \
								$(addprefix utils/, \
									solution_bonus.c \
									calc_normal_max_bonus.c \
								) \
							) \
							$(addprefix set_objects/, \
								line_list_to_bvh_bonus.c \
								set_objects_bonus.c \
								$(addprefix hitter_arr_to_bvh/, \
									bvh_utils_bonus.c \
									compare_bonus.c \
									construct_hitter_arr_bonus.c \
									find_best_split_info_bonus.c \
									prepare_surface_arr_bonus.c \
									generate_hitter_list_bonus.c \
									generate_tree_bonus.c \
									hit_arr_to_bvh_bonus.c \
									split_bonus.c \
								) \
								$(addprefix line_list_to_hitter_arr/, \
									add_cylinder_disk_bonus.c \
									add_hitter_list_bonus.c \
									line_list_to_hit_arr_bonus.c \
									line_list_to_hitter_list_bonus.c \
								) \
							) \
						) \
						$(addprefix utils/, \
							has_object_in_line_list_bonus.c \
							str_to_idx_bonus.c \
							match_identifer_bonus.c \
							search_object_bonus.c \
							token_to_str_bonus.c \
							token_to_value_bonus.c \
							token_to_vec_bonus.c \
						) \
					) \
					$(addprefix render_world/, \
						render_world_bonus.c \
						$(addprefix render_pixels/, \
							$(addprefix compute_phong_color/, \
								calc_color_from_light_list_bonus.c \
								compute_phong_color_bonus.c \
							) \
							calc_sample_pixel_color_bonus.c \
							compute_path_tracing_color_bonus.c \
							render_pixels_bonus.c \
							thread_render_bonus.c \
						) \
						$(addprefix draw_image/, \
							$(addprefix utils/, \
								$(addprefix draw_mlx_image/, \
									mlx_utils_bonus.c \
									draw_mlx_image_bonus.c \
								) \
								draw_ppm_image_bonus.c \
							) \
							draw_image_bonus.c \
						) \
					) \
					$(addprefix ray/, \
						ray_bonus.c \
					) \
					$(addprefix utils/, \
						clock_bonus.c \
						construct_result_bonus.c \
						ft_qsort_bonus.c \
						ft_swap_bonus.c \
						utils_clamp_bonus.c \
						utils_clear_bonus.c \
						utils_err_bonus.c \
						utils_float_bonus.c \
						utils_random_bonus.c \
						$(addprefix vec/, \
							onb_bonus.c \
							range_bonus.c \
							vec2_bonus.c \
							vec3_bonus.c \
							vec3_basic_bonus.c \
							vec3_product_bonus.c \
							vec3_scal_bonus.c \
							reflect_bonus.c \
						) \
					) \
				)

# --- obj ---
OBJDIR			=	obj
OBJS			=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

OBJDIR_BONUS	=	obj_bonus
OBJS_BONUS		=	$(patsubst $(SRCDIR_BONUS)/%.c, $(OBJDIR_BONUS)/%.o, $(SRCS_BONUS))

ifeq ($(MAKECMDGOALS),bonus)
	BUILD_OBJS	:=	$(OBJS_BONUS)
else ifeq ($(MAKECMDGOALS),rebonus)
	BUILD_OBJS	:=	$(OBJS_BONUS)
else
	BUILD_OBJS	:=	$(OBJS)
endif

# --- deps ---
DEPS		=	$(BUILD_OBJS:.o=.d)

# --- include ---
ifeq ($(MAKECMDGOALS),bonus)
	INCDIRS	:=	$(shell find include_bonus -type d)
else ifeq ($(MAKECMDGOALS),rebonus)
	INCDIRS	:=	$(shell find include_bonus -type d)
else
	INCDIRS	:=	$(shell find include -type d)
endif

# --- OS DETECTION ---
UNAME	=	$(shell uname -s)
ifeq ($(UNAME),Darwin)
	MLXDIR := minilibx_macos
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
DFLAG		=	-g -O0
ASANFLAG	=	$(DFLAG) -fsanitize=address
SCANBUILD	=	/usr/bin/scan-build-12

# --- test ---
TESTNAME	=	test_miniRT
TESTCFLAG	=	$(ASANFLAG) -Itest/utils
TESTLDFLAG	=	$(LDFLAG) -Wl,--wrap=open,--wrap=read,--wrap=malloc,--wrap=free,--wrap=exit

TESTSRCFILES	=	$(addprefix test/, \
						test.c \
						test_mini_rt.c \
						$(addprefix unit/, \
							test_unit.c \
							test_match_identifer.c \
							test_set_option.c \
							test_read_rt_file.c \
							test_is_valid_file_name.c \
							test_is_valid_option.c \
							test_line_to_value.c \
							test_skip_color.c \
							test_skip_point.c \
							test_skip_range.c \
							test_skip_spaces.c \
							test_skip_unit.c \
							test_skip_until_end.c \
							test_set_ambient.c \
							test_set_camera.c \
							test_add_light_radius.c \
							test_line_to_light.c \
							test_is_component_higher.c \
							test_ft_swap.c \
							test_pertition.c \
						) \
						$(addprefix utils/, \
							syscall_mock.c \
							vec_equal.c \
						))

TESTSRCS		=	$(TESTSRCFILES) \
					$(filter-out $(SRCDIR)/main.c, $(SRCS))
TESTOBJS		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(TESTSRCS))

# --- Rules ---
all: $(NAME)

bonus:	$(NAME)

$(NAME): $(BUILD_OBJS)
	$(CC) $(CFLAG) $^ $(LDFLAG) $(LDLIBS) -o $@
	@echo "\n\033[1;32m'$(NAME)' has been created!\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) bonus

$(MLX):
	git clone $(GITHUBURL) $(MLXDIR)
	@$(MAKE) -C $(MLXDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(LIBFT) $(MLX)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAG) -c $< -o $@

$(OBJDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c $(LIBFT) $(MLX)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAG) -c $< -o $@

clean:
	@$(RMDIR) $(OBJDIR)
	@$(RMDIR) $(OBJDIR_BONUS)

fclean: clean
	$(RM) $(NAME) $(TESTNAME)

re: fclean all

rebonus: fclean bonus

# --- DEBUGGIN & TESTING ---
lldba:
	$(MAKE) CFLAG="$(CFLAG) $(DFLAG)"
	@echo "\n\033[1;35mLaunching LLDB for '$(NAME)'...\033[0m"
	@lldb $(NAME)

# --- address sanitizer ---
asan:fclean
	$(MAKE) LDFLAG="$(LDFLAG) $(ASANFLAG)" "CFLAG=$(CFLAG) $(ASANFLAG)"
	@echo "\n\033[1;35mCompiled with AddressSanitizer. Run './$(NAME)' to test.\033[0m"

# --- valgrind ---
valgrind:
	$(MAKE) re CFLAG="$CFLAG $(DFLAG)"
	@echo "\n\033[1;36mRunning Valgrind for '$(NAME)'...\033[0m"
	$(VALGRIND) $(VALGRIND_FLAG) ./$(NAME)

# --- debug ---
debug:
	$(MAKE) re CFLAG="$(CFLAG) $(DFLAG)"

# --- test ---
test:
	@$(MAKE) CFLAG="$(CFLAG) $(TESTCFLAG)" LDFLAG=" $(TESTLDFLAG)" $(TESTNAME)
	@echo "\033[1;36mRunning tests ...\033[0m"
	./$(TESTNAME)
	@echo "\n\033[1;32mall test passed\033[0m"

$(TESTNAME):$(TESTOBJS) $(MLX) $(LIBFT)
	$(CC) $(TESTOBJS) $(CFLAG) $(TESTLDFLAG) $(LDLIBS) -o $@

# --- scan build ---$(INCDIRS)/test/
scanb: fclean
	@$(SCANBUILD) $(MAKE) all

.PHONY:	all clean fclean re bonus rebonus test debug asan valgrind scanb

-include	$(DEPS)
