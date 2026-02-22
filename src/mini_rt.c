/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:00:17 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/22 20:31:19 by ikawamuk         ###   ########.fr       */
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

#include "material.h" // debug
#include "rt_debug.h" // debug
#include <stdio.h> // debug
#include <stdlib.h> // debug
void	print_world(const t_world *world); // debug
void	print_option(int option_flag); // debug

int	mini_rt(int argc, char *argv[])
{
	int		option_flag;
	t_world	world;

	validate_arguments(argc, argv);
	option_flag = set_option(argv + 2);
	// print_option(option_flag);
	if (init_world(&world, argv[1], option_flag) == FAILURE)
		return (FAILURE);
	print_world(&world);
	if (render_world(&world, option_flag) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
