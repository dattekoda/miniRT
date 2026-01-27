/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:53:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/27 22:22:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "libft.h"
#include <assert.h>

int	test_add_light_radius(void);
int	test_line_to_light(void);
int	add_light_radius(char **light_line, t_point3 camera_origin);


int	test_set_light(void)
{
	test_add_light_radius();
	// test_line_to_light();
	return (0);
}
