/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:26:06 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 16:38:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "util_rt.h"
#include "libft.h"

int			validate_arguments(int argc, char *argv[]);
int			read_rt_file(t_list **line_list, const char *file_path);
int			validate_rt_file(const t_list *line_list);
int			set_option(const char *options);
int			create_world(t_world *world, char *file_path);

// if (create_world(world, argv[1]) == FAILURE)
// 	return (FAILURE);
int	init_world(t_world *world, int argc, char *argv[])
{
	t_list	*line_list;

	if (validate_arguments(argc, argv) == FAILURE)
		return (FAILURE);
	if (read_rt_file(&line_list, argv[1]) == FAILURE)
		return (FAILURE);
	if (validate_rt_file(line_list) == FAILURE)
		return (FAILURE);
	line_list = NULL;
	world->option_flag = set_option(argv[2]);
	return (SUCCESS);
}
