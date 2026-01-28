/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_add_light_radius.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:24:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/27 21:02:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "result.h"
#include "rt_define.h"
#include "libft.h"
#include <math.h>
#include <assert.h>
#include <stdio.h>

int	add_light_radius(char **light_line, t_point3 camera_origin);

/*
@brief -> L ...... expected_radius + 1
*/
int	test_add_light_radius(void)
{
	char			*line;
	const double	expected_radius = 1.0;
	double			sample_xyz;

	sample_xyz = sqrt(pow(expected_radius/sqrt((LIGHT_STERADIAN/M_PI)-pow(LIGHT_STERADIAN/(2*M_PI),2)), 2)/3.0);
	line = ft_strdup("L 0,0,0 1 255,255,255");
	assert(line != NULL);
	assert(add_light_radius(&line, (t_point3){{sample_xyz, sample_xyz, sample_xyz}}) == SUCCESS
		&& !ft_strcmp(line, "L 0,0,0 1 255,255,255 2"));
	return (0);
}
