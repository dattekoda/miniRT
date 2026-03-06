/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:00:17 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 15:59:37 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "result.h"
#include "option.h"
#include "rt_utils.h"
#include "libft.h"
#include <stdlib.h>

void	validate_arguments(int argc, char *argv[]);
int		set_option(char *options[]);
int		init_world(t_world *world, char *file_name, int option_flag);
int		render_world(t_world *world, int option_flag);
#include "rt_debug.h"

int	mini_rt(int argc, char *argv[])
{
	int		option_flag;
	t_world	world;

	validate_arguments(argc, argv);
	option_flag = set_option(argv + 2);
	if (init_world(&world, argv[1], option_flag) == FAILURE)
		return (FAILURE);
	init_time();
	if (render_world(&world, option_flag) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
