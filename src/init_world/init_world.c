/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:26:06 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/11 21:29:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "result.h"
#include "libft.h"
#include <stdlib.h>

void	read_rt_file(t_list **line_list, const char *file_path);
bool	is_valid_line_list(const t_list *line_list, int option_flag);
int		create_world(t_world *world, t_list *line_list, int option_flag);

/*
@brief responsible for free line_list
*/
int	init_world(t_world *world, char *file_path, int option_flag)
{
	t_list	*line_list;

	line_list = NULL;
	read_rt_file(&line_list, file_path);
	ft_bzero(world, sizeof(t_world));
	if (!is_valid_line_list(line_list, option_flag))
	{
		ft_lstclear(&line_list, free);
		exit(EXIT_FAILURE);
	}
	if (create_world(world, line_list, option_flag) == FAILURE)
	{
		ft_lstclear(&line_list, free);
		exit(EXIT_FAILURE);
	}
	ft_lstclear(&line_list, free);
	return (SUCCESS);
}
