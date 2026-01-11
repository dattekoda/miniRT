/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:00:17 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/11 15:39:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"

#include <stdio.h>

int	init_world(t_world *world, int argc, char *argv[]);

int	mini_rt(int argc, char *argv[])
{
	t_world	world;

	
	if (init_world(&world, argc, argv))
		return (FAILURE);
	printf("Hello miniRT!\n");
	return (SUCCESS);
}
