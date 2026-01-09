/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:26:06 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/10 00:13:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "util_rt.h"
#include "libft.h"
#include <stdlib.h>

void		validate_arguments(int argc, char *argv[]);
void		read_rt_file(t_list **line_list, const char *file_path);
int			validate_line_list(const t_list *line_list);
int			set_option(const char *options);
int			create_world(t_world *world, char *file_path);

int	init_world(t_world *world, int argc, char *argv[])
{
	t_list	*line_list;

	validate_arguments(argc, argv);
	read_rt_file(&line_list, argv[1]);
	line_list = NULL;
	if (validate_line_list(line_list) == FAILURE)
	{
		ft_lstclear(&line_list, free);
		exit(EXIT_FAILURE);
	}
	if (create_world(world, line_list) == FAILURE)
	{
		ft_lstclear(&line_list, free);
		exit(EXIT_FAILURE);
	}
	ft_lstclear(&line_list, free);
	world->option_flag = set_option(argv[2]);
	return (SUCCESS);
}
