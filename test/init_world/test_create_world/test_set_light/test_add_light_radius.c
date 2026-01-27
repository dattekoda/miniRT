/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_add_light_radius.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:24:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/27 20:35:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "result.h"
#include "libft.h"
#include <assert.h>

int	add_light_radius(char **light_line, t_point3 camera_origin);

#define LIGHT_STERADIAN 0.1

int	test_add_light_radius(void)
{
	char	*line;
	static const double sample_xyz = 3.2489963543;

	line = ft_strdup("L 0,0,0 1 255,255,255");
	assert(line != NULL);
	assert(add_light_radius(&line, (t_point3){{sample_xyz, sample_xyz, sample_xyz}}) == SUCCESS
		&& !ft_strcmp(line, "L 0,0,0 1 255,255,255 2"));
	return (0);
}