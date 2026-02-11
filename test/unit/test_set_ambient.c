/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:54:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/07 21:15:39 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"
#include "vec.h"
#include <stdbool.h>
#include <assert.h>

t_color	line_to_ambient_light(const char *line, bool is_phong);
bool	vec3_equal(t_vec3 a, t_vec3 b);

int	test_line_to_ambient_light(void)
{
	assert(vec3_equal(line_to_ambient_light("A 1.0 255, 255 , 255", 0),
					(t_color){{100.0, 100.0, 100.0}}));
	assert(vec3_equal(line_to_ambient_light("A 0.5 255, 255 , 255", 0),
					(t_color){{50.0, 50.0, 50.0}}));
	assert(vec3_equal(line_to_ambient_light("A 1.0 200, 150 , 100", 0),
					(t_color){{78.43137255, 58.82352941, 39.21568627}}));

	assert(vec3_equal(line_to_ambient_light("A 1.0 255, 255 , 255", OPT_ARTIFICIAL),
					(t_color){{1.0, 1.0, 1.0}}));
	assert(vec3_equal(line_to_ambient_light("A 0.5 255, 255 , 255", OPT_ARTIFICIAL),
					(t_color){{0.5, 0.5, 0.5}}));
	assert(vec3_equal(line_to_ambient_light("A 1.0 200, 150 , 100", OPT_ARTIFICIAL),
					(t_color){{0.7843137255, 0.5882352941, 0.3921568627}}));
	return (0);
}


