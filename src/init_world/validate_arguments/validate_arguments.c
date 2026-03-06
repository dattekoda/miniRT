/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:21:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/06 22:54:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "rt_utils.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	put_format(void);
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
		ft_putendl_fd("See \'./miniRT -h\' for help\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_strcmp("-h", argv[1]))
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
	ft_putendl_fd("Usage: ./miniRT <.rt file> [OPTION]", STDERR_FILENO);
	put_format();
	ft_putendl_fd("\noptions:", STDERR_FILENO);
	ft_putendl_fd("\t-a artificial mode: use Phong reflection model",
		STDERR_FILENO);
	ft_putendl_fd("\t-m define object materials. "\
"-- lambertian, metal, dielectric for material", STDERR_FILENO);
	ft_putendl_fd("\t                            "\
"-- solid, checker, bump for texture", STDERR_FILENO);
	ft_putendl_fd("\t-p ppm mode: out put ppm file", STDERR_FILENO);
}

static void	put_format(void)
{
	size_t	i;

	ft_putendl_fd("\nformats:", STDERR_FILENO);
	i = 0;
	while (g_element_table[i])
		ft_putendl_fd(g_element_table[i++]->input_format, STDERR_FILENO);
	return ;
}
