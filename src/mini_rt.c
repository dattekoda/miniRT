/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:00:17 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/07 22:29:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "result.h"
#include <stdlib.h>

void	init_time(void);
void	validate_arguments(int argc, char *argv[]);
int		set_option(char *options[]);
int		init_world(t_world *world, char *file_name, int option_flag);
int		render_world(t_world *world, int option_flag);

int	mini_rt(int argc, char *argv[])
{
	t_world	world;
	int		option_flag;

	init_time();
	validate_arguments(argc, argv);
	option_flag = set_option(argv + 2);
	if (init_world(&world, argv[1], option_flag) == FAILURE)
		return (FAILURE);
	if (render_world(&world, option_flag) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
