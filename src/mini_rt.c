/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:00:17 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/16 17:05:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h> // 後で消す

int	init_world(t_world *world, int argc, char *argv[]);

int	mini_rt(int argc, char *argv[])
{
	t_world	world;

	ft_bzero(&world, sizeof(t_world));
	if (init_world(&world, argc, argv))
		return (EXIT_FAILURE);
	printf("Hello miniRT!\n");
	return (EXIT_SUCCESS);
}
