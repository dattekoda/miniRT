/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:26:06 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 22:43:48 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "util_rt.h"
#include "libft.h"

void		validate_arguments(int argc, char *argv[]);
void		read_rt_file(t_list **line_list, const char *file_path);
int			validate_line_list(const t_list *line_list);
int			set_option(const char *options);
int			create_world(t_world *world, char *file_path);

// if (create_world(world, argv[1]) == FAILURE)
// 	return (FAILURE);
int	init_world(t_world *world, int argc, char *argv[])
{
	t_list	*line_list;

	validate_arguments(argc, argv);
	read_rt_file(&line_list, argv[1]);
	if (validate_line_list(line_list) == FAILURE)
		return (FAILURE);
	line_list = NULL;
	world->option_flag = set_option(argv[2]);
	ft_lstclear(&line_list, free);
	return (SUCCESS);
}
