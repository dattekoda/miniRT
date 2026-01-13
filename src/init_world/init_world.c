/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:26:06 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/14 00:09:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"
#include "result.h"
#include "world.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	validate_arguments(int argc, char *argv[]);
static int	validate_file_name(const char *file_path);
void		read_rt_file(t_list **line_list, const char *file_path);
int			validate_line_list(const t_list *line_list);
int			set_option(const char *options);
int			create_world(t_world *world, t_list *line_list);

/*
@brief line_listの開放責務を持つ
*/
int	init_world(t_world *world, int argc, char *argv[])
{
	t_list	*line_list;

	validate_arguments(argc, argv);
	line_list = NULL;
	read_rt_file(&line_list, argv[1]);
	if (validate_line_list(line_list) == FAILURE)
	{
		ft_lstclear(&line_list, free);
		exit(EXIT_FAILURE);
	}
	world->option_flag = set_option(argv[2]);
	if (create_world(world, line_list) == FAILURE)
	{
		ft_lstclear(&line_list, free);
		exit(EXIT_FAILURE);
	}
	ft_lstclear(&line_list, free);
	return (SUCCESS);
}

/*
@brief validate function
@param argv_one argv[1]
*/
void	validate_arguments(int argc, char *argv[])
{
	if (argc == 1)
	{
		err_rt("set .rt file as first argument");
		exit(EXIT_FAILURE);
	}
	if (validate_file_name(argv[1]) == FAILURE)
		exit(EXIT_FAILURE);
	return ;
}

/*
@brief Check if the file name of argument is correct.
@param file_path just argv[1]
*/
int	validate_file_name(const char *file_path)
{
	size_t		rt_file_len;
	const char	*rt_file;

	rt_file = ft_strchr(file_path, '/');
	if (rt_file)
		rt_file += 1;
	else
		rt_file = file_path;
	rt_file_len = ft_strlen(rt_file);
	if ((rt_file[0] == '.') \
|| (rt_file_len <= 3 || ft_strcmp(rt_file + rt_file_len - 3, ".rt") != 0))
	{
		err_rt("invalid file name");
		return (FAILURE);
	}
	return (SUCCESS);
}
