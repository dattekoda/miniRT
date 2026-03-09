/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:21:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:32:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_bonus.h"
#include "init_world_utils_bonus.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void		put_format(void);
static void	print_help(void);
bool		is_valid_file_name(const char *file_path);
bool		is_valid_option(char **options);

/*
@brief validate function
@param argv_one argv[1]
*/
void	validate_arguments(int argc, char *argv[])
{
	if (argc == 1)
	{
		err_rt("set .rt file as first argument");
		put_format();
		ft_putendl_fd("\nSee \'./miniRT --help\' for help", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_strcmp("-h", argv[1]) || !ft_strcmp("--help", argv[1]))
	{
		print_help();
		exit(EXIT_SUCCESS);
	}
	if (!is_valid_file_name(argv[1]))
		exit(EXIT_FAILURE);
	if (argc >= 3 && !is_valid_option(argv + 2))
		exit(EXIT_FAILURE);
	return ;
}

static void	print_help(void)
{
	ft_putendl_fd("Usage: ./miniRT <.rt file> [OPTION]", STDOUT_FILENO);
	put_format();
	ft_putendl_fd("\noptions:", STDOUT_FILENO);
	ft_putendl_fd("\t-a, --artificial: artificial mode."\
"use Phong reflection model",
		STDOUT_FILENO);
	ft_putendl_fd("\t-m, --material: define object materials. "\
"-- lambertian, metal, dielectric for material", STDOUT_FILENO);
	ft_putendl_fd("\t                                         "\
"-- solid, checker, bump for texture", STDOUT_FILENO);
	ft_putendl_fd("\t-p, --ppm: ppm mode: out put ppm file", STDOUT_FILENO);
	ft_putendl_fd("\t-h, --help: print help", STDOUT_FILENO);
}

void	put_format(void)
{
	size_t	i;

	ft_putendl_fd("\nformats:", STDERR_FILENO);
	i = 0;
	while (g_element_table[i])
		ft_putendl_fd(g_element_table[i++]->input_format, STDERR_FILENO);
	return ;
}
