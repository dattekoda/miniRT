/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_skip_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:44:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 20:40:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include <math.h>
#include <assert.h>

t_result	skip_range(const char *line, size_t *line_idx, \
double min, double max);

int	test_skip_range(void)
{
	size_t	i;

	i = 0;
	assert(skip_range(" 0 ", &i, 0, 1).state == SUCCESS && i == 2);
	i = 0;
	assert(skip_range(" -0 ", &i, 0, 1).state == SUCCESS && i == 3);

	i = 0;
	assert(skip_range(" 1.01 ", &i, 0, 1).state == FAILURE && i == 4);
	i = 0;
	assert(skip_range(" inf ", &i, -INFINITY, INFINITY).state == FAILURE && i == 3);
	return (0);
}
