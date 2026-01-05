/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:00:17 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/05 22:24:27 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "validate_rt.h"
#include "util_rt.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	err_argc(void);
int	init_world(t_world *world, int argc, char *argv[]);

int	mini_rt(int argc, char *argv[])
{
	t_world	world;

	init_world(&world, argc, argv);
	err_argc();
	printf("Hello miniRT!\n");
	return (0);
}

static void	err_argc(void)
{
	err_rt();
	ft_putendl_fd("Set a .rt file as an argument.", STDERR_FILENO);
}
