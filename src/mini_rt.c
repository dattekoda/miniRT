/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:00:17 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/26 16:01:52 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "result.h"
#include "libft.h"
#include <stdlib.h>

int	init_world(t_world *world, int argc, char *argv[]);

int	mini_rt(int argc, char *argv[])
{
	t_world	world;

	ft_bzero(&world, sizeof(t_world));
	if (init_world(&world, argc, argv) == FAILURE)
		return (EXIT_FAILURE);
	ft_putendl_fd("Hello, miniRT!", 1);
	return (SUCCESS);
}
