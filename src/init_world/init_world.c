/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:26:06 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/24 16:06:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "result.h"
#include "libft.h"
#include <stdlib.h>

void	validate_arguments(int argc, char *argv[]);
void	read_rt_file(t_list **line_list, const char *file_path);
bool	is_valid_line_list(const t_list *line_list, int option_flag);
int		set_option(const char *options);
int		create_world(t_world *world, t_list *line_list);

/*
@brief line_listの開放責務を持つ
*/
int	init_world(t_world *world, int argc, char *argv[])
{
	t_list	*line_list;

	validate_arguments(argc, argv);
	world->option_flag = set_option(argv + 2);
	line_list = NULL;
	read_rt_file(&line_list, argv[1]);
	if (!is_valid_line_list(line_list, world->option_flag))
	{
		ft_lstclear(&line_list, free);
		exit(EXIT_FAILURE);
	}
	// ここから上はOK
	if (create_world(world, line_list) == FAILURE)
	{
		ft_lstclear(&line_list, free);
		exit(EXIT_FAILURE);
	}
	ft_lstclear(&line_list, free);
	return (SUCCESS);
}
